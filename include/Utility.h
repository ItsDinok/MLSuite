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
#include <math.h>

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
std::unordered_map<int, double> pearson_correlation(std::vector<std::vector<double>>& table, std::vector<int>& classes);

// ML Metrics
double compute_accuracy(std::vector<int>& predictions, std::vector<int>& truth);
double compute_precision(std::vector<int>& predictions, std::vector<int>& truth);
double compute_recall(std::vector<int>& predictions, std::vector<int>& truth);
double compute_f1_score(std::vector<int>& predictions, std::vector<int>& truth);

// Maths/Table helpers
double average_column(std::vector<std::vector<double>>& table, int column);
double average_vector_ints(std::vector<int>& table);
