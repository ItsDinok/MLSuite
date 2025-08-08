#include <iostream>
#include "Utility.h"
#include "LogisticRegression.h"

int main() 
{
	std::string path = "../Datasets/diabetes.csv";
	std::vector<std::vector<double>> dataset;
	std::vector<int> classes;
	
	parse_csv(dataset, classes, path);
	
	Logistic_Regressor model(dataset[0].size());
	model.Fit(dataset);

	std::vector<int> predictions;
	model.Predict(dataset, predictions);

	double accuracy = compute_accuracy(predictions, classes);
	std::cout << "Accuracy: " << compute_accuracy << std::endl;
}
