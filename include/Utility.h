#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <random>

// File IO
void parse_csv(std::vector<std::vector<double>>& out_set, std::vector<int>& labels,  std::string& path);
void train_test_split(
	std::vector<std::vector<double>>& input_x,
	std::vector<int>& input_y,
	std::vector<std::vector<double>>& train_x,
	std::vector<std::vector<double>>& test_x,
	std::vector<int>& train_y,
	std::vector<int>& test_y,
	float proportion
);
void shuffle_sets(std::vector<std::vector<double>>& x_set, std::vector<int>& y_set);

// Feature preprocessing
void normalise(std::vector<std::vector<double>>& table);
void clean_illegal_zeros(std::vector<std::vector<double>>& table, const std::vector<int>& illegal_zeros);
void remove_illegal_zeros(std::vector<std::vector<double>>& table, const std::vector<int>& illegal_zeros);

// ML Metrics
double compute_accuracy(std::vector<int>& predictions, std::vector<int>& truth);

