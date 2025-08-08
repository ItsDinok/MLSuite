#include "LogisticRegression.h"

Logistic_Regressor::Logistic_Regressor(int extern_features)
{
	features = extern_features;

	// TODO: Random tiny initialisation
	for (int i = 0; i < features; ++i)
	{
		weights.push_back(i);
	}
}

double Logistic_Regressor::Logistic_Function(std::vector<double>& values)
{
	double z = Sum_Of_Inputs(values);
	double base = pow(E, -z);

	return 1 / (1 + base);
}

double Logistic_Regressor::Sum_Of_Inputs(std::vector<double>& values)
{
	double total = 0.0d;

	for (int i = 0; i < weights.size(); ++i) 
	{
		total += weights[i] * values[i];
	}

	return total;
}

void Logistic_Regressor::Fit(std::vector<std::vector<double>>& dataset)
{
	for (int z = 0; z < epochs; ++z)
	{
		for (int i = 0; i < dataset.size(); ++i)
		{
			std::vector<double> sample = dataset[i];
			double log = Logistic_Function(sample); // NOT related to log in math
			int prediction;

			if (log >= 0.5) prediction = 1;
			else prediction = 0;

			Gradient_Descent(sample[i], prediction, sample);
		}
	}
}

void Logistic_Regressor::Gradient_Descent(int truth, double guess, std::vector<double>& feature_values)
{
	// Weight = weight - learning rate * (guess - truth) * feature value
	for (int i = 0; i < features; ++i)
	{
		double initial = weights[i];
		double feature_value = feature_values[i];

		weights[i] = initial - learning_rate * (guess - truth) * feature_value;
	}
}

void Logistic_Regressor::Predict(std::vector<std::vector<double>>& dataset, std::vector<int>& predictions)
{
	for (int i = 0; i < dataset.size(); ++i)
	{
		std::vector<double> sample = dataset[i];
		double log = Logistic_Function(sample);

		if (log >= 0.5) predictions.push_back(1);
		else predictions.push_back(0);
	}
}
