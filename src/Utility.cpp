#include "Utility.h"

void parse_csv(std::vector<std::vector<double>>& out_set, std::vector<std::string>& labels, std::string& path)
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
		for (int i = 0; i < line.size(); ++i) 
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

double compute_accuracy(std::vector<int>& predictions, std::vector<int>& truth)
{
	int total = predictions.size();
	int correct = 0;

	for (int i = 0; i < total; ++i)
	{
		if (predictions[i] == truth[i])
		{
			++correct;
		}
	}

	return correct / total;
}
