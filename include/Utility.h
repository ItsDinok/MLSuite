#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

void parse_csv(std::vector<std::vector<double>>& out_set, std::vector<std::string>& labels,  std::string& path);

double compute_accuracy(std::vector<int>& predictions, std::vector<int>& truth);
