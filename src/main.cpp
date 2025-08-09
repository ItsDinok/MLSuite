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
	
	// Get and clean data
	parse_csv(dataset, classes, path);
	normalise(dataset);

	// Train/test data structures
	std::vector<std::vector<double>> x_train;
	std::vector<std::vector<double>> x_test;
	std::vector<int> y_train;
	std::vector<int> y_test;
	const float PROPORTION = 0.8f;
	train_test_split(dataset, classes, x_train, x_test, y_train, y_test, PROPORTION);

	std::cout << "x_train size: " << x_train.size() << std::endl;
	std::cout << "y_train size: " << y_train.size() << std::endl;
	std::cout << "x_test size: " << x_test.size() << std::endl;
	std::cout << "y_test size: " << y_test.size() << std::endl;


	Logistic_Regressor model(dataset[0].size());
	model.Fit(x_train, y_train);
	std::cout << "Model fitted" << std::endl;

	std::vector<int> predictions;
	model.Predict(x_test, predictions);

	std::cout << "Predictions size: " << predictions.size() << std::endl;

	double accuracy = compute_accuracy(predictions, y_train);
	std::cout << "Accuracy: " << accuracy << std::endl;
}
