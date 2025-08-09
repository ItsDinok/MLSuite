#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <utility>
#include <algorithm>

// File IO
void parse_csv(std::vector<std::vector<double>>& out_set, std::vector<int>& labels,  std::string& path);

// Feature preprocessing
void normalise(std::vector<std::vector<double>>& table);
void clean_illegal_zeros(std::vector<std::vector<double>>& table, const std::vector<int>& illegal_zeros);
void remove_illegal_zeros(std::vector<std::vector<double>>& table, const std::vector<int>& illegal_zeros);

// ML Metrics
double compute_accuracy(std::vector<int>& predictions, std::vector<int>& truth);
