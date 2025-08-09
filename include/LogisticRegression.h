#pragma once
#include <random>
#include <math.h>
#include <vector>
#include <iostream>

class Logistic_Regressor 
{
public:
	// Methods
	Logistic_Regressor(int extern_features);
	Logistic_Regressor(int extern_features, std::vector<int>& parameters);
	double Logistic_Function(std::vector<double>& values); 
	void Gradient_Descent(int truth, double guess, std::vector<double>& feature_values);
	void Fit(std::vector<std::vector<double>>& dataset, std::vector<int>& truths);
	void Predict(std::vector<std::vector<double>>& dataset, std::vector<int>& predictions);

	// Attributes
	const double E = 2.71828182845904523536;
private:
	// Methods
	double Sum_Of_Inputs(std::vector<double>& values);

	// Attributes
	std::vector<double> weights;
	int features;
	int epochs = 250;
	double learning_rate = 0.001;
};
