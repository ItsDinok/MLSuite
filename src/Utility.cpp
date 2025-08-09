#include "Utility.h"

void parse_csv(std::vector<std::vector<double>>& out_set, std::vector<int>& labels, std::string& path)
{
	// This assumes the header row is useless information and the last column is a label
	// It also assumes comma delineation
	std::ifstream csv(path);
	std::string line;
	bool is_first = true;

	while (std::getline(csv, line))
	{
		if (is_first) 
		{
			is_first = false;
			continue;
		}

		std::vector<double> new_line;
		std::string buffer = "";
		for (size_t i = 0; i < line.size(); ++i) 
		{
			if (line[i] == ',') 
			{
				new_line.push_back(std::stod(buffer));
				buffer = "";
				continue;
			}
			buffer += line[i];
		}

		// The last column is assumed to be label
		labels.push_back(std::stoi(buffer));
		out_set.push_back(new_line);
	}
}

void normalise(std::vector<std::vector<double>>& table)
{
	// Basic min/max scaling
	std::unordered_map<int, std::pair<double, double>> min_max_values;
	
	// Outer loop is feature
	for (size_t i = 0; i < table[0].size(); ++i)
	{
		double min = std::numeric_limits<double>::max();
		double max = std::numeric_limits<double>::min();

		for (size_t j = 0; j < table.size(); ++j)
		{
			if (table[j][i] > max) max = table[j][i];
			if (table[j][i] < min) min = table[j][i];			
		}

		std::pair<double, double> to_push = std::make_pair(min, max);
		min_max_values[i] = to_push;
	}

	// Normalise across table
	for (size_t i = 0; i < table[0].size(); ++i)
	{
		for (size_t j = 0; j < table.size(); ++j)
		{
			double updated = table[j][i] - min_max_values[i].first;
			updated /= (min_max_values[i].second - min_max_values[i].first);
			table[j][i] = updated;
		}
	}
}

void clean_illegal_zeros(std::vector<std::vector<double>>& table, const std::vector<int>& illegal_zeros)
{
	// illegal_zeros is a list of features which cannot be zero
	for (size_t i = 0; i < table[0].size(); ++i)
	{
		if (std::find(illegal_zeros.begin(), illegal_zeros.end(), i) != illegal_zeros.end())
		{
			double total = 0.0d;
			// Calculate mean value
			for (size_t j = 0; j < table.size(); ++j)
			{
				if (table[i][j] == 0) continue;
				total += table[i][j];
			}

			double mean = total / table.size();

			for (size_t j = 0; j < table.size(); ++j)
			{
				if (table[j][i] == 0)
				{
					table[j][i] = mean;
				}
			}
		}
	}
}

// TODO: I am convinced this skips values and can cause a segfault
void remove_illegal_zeros(std::vector<std::vector<double>>& table, const std::vector<int>& illegal_zeros)
{
	for (size_t i = 0; i < table[0].size(); ++i)
	{
		if (std::find(illegal_zeros.begin(), illegal_zeros.end(), i) != illegal_zeros.end())
		{
			for (size_t j = 0; j < table.size(); ++j)
			{
				if (table[j][i] == 0) table.erase(table.begin() + j);
			}
		}
	}


}

double compute_accuracy(std::vector<int>& predictions, std::vector<int>& truth)
{
	size_t total = predictions.size();
	int correct = 0;

	for (size_t i = 0; i < total; ++i)
	{
		if (predictions[i] == truth[i])
		{
			++correct;
		}
	}

	return static_cast<double>(correct) / total;
}
