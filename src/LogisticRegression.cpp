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

double Logistic_Regressor::Logistic_Function()
{
	double z = Sum_Of_Inputs();
	double base = pow(E, -z);

	return 1 / (1 + base);
}

double Logistic_Regressor::Sum_Of_Inputs()
{
	// This gets the sum of input feature weights
	double total = 0.0d;
	
	for (int i = 0; i < weights.size(); ++i) 
	{
		total += weights[i];
	}

	return total;
}
