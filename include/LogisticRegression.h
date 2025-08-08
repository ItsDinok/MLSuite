#pragma once
#include <random>
#include <math.h>

class Logistic_Regressor 
{
public:
	// Methods
	Logistic_Regressor(int extern_features);
	double Logistic_Function(); 
	void Gradient_Descent();
	double Calculate_Loss();

	// Attributes
	const double E = 2.71828182845904523536;
private:
	// Methods
	double Sum_Of_Inputs();

	// Attributes
	std::vector<double> weights;
	int features;
};
