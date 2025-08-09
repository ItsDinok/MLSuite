#include <iostream>
#include "Utility.h"
#include "LogisticRegression.h"

// Feature indices that cannot be zero in the diabetes dataset
const std::vector<int> ILLEGAL_ZEROS_DIABETES = {
	1,2,3,4,5,6,7
};

int main() 
{
	std::string path = "../Datasets/diabetes.csv";
	std::vector<std::vector<double>> dataset;
	std::vector<int> classes;
	
	parse_csv(dataset, classes, path);
	normalise(dataset);
	//remove_illegal_zeros(dataset, ILLEGAL_ZEROS_DIABETES);

	Logistic_Regressor model(dataset[0].size());
	model.Fit(dataset, classes);
	std::cout << "Got here" << std::endl;

	std::vector<int> predictions;
	model.Predict(dataset, predictions);

	std::cout << "Predictions size: " << predictions.size() << std::endl;

	double accuracy = compute_accuracy(predictions, classes);
	std::cout << "Accuracy: " << accuracy << std::endl;
}
