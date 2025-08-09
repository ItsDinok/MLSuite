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

void train_test_split( std::vector<std::vector<double>>& input_x, std::vector<int>& input_y, 
		std::vector<std::vector<double>>& train_x, std::vector<std::vector<double>>& test_x, 
		std::vector<int>& train_y, std::vector<int>& test_y, float proportion)
{
	// Shuffle
	shuffle_sets(input_x, input_y);

	// Split by proportion
	int limit = input_x.size() * proportion;
	for (size_t i = 0; i < input_x.size(); ++i)
	{
		if (i < limit) 
		{
			train_x.push_back(input_x[i]);
			train_y.push_back(input_y[i]);
		}
		else
		{
			test_x.push_back(input_x[i]);
			test_y.push_back(input_y[i]);
		}
	}
}

void shuffle_sets(std::vector<std::vector<double>>& x_set, std::vector<int>& y_set)
{
	std::vector<std::vector<double>> inplace_x;
	std::vector<int> inplace_y;
	std::vector<int> used; // TODO: This approach is woefully inefficient

	std::random_device rd;
	std::mt19937 gen(rd());

	for(size_t i = 0; i < x_set.size(); ++i)
	{
		std::uniform_int_distribution<> distr(i, x_set.size());
		while (true) 
		{
			int index = distr(gen);
			if (std::find(used.begin(), used.end(), index) != used.end()) continue;

			inplace_x.push_back(x_set[index]);
			inplace_y.push_back(y_set[index]);

			break;
		}
	}

	for (size_t i = 0; i < x_set.size(); ++i)
	{
		x_set[i] = inplace_x[i];
		y_set[i] = inplace_y[i];
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
