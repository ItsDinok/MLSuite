#include <iostream>
#include "Utility.h"

int main() 
{
	std::string path = "../Datasets/diabetes.csv";
	std::vector<std::vector<double>> dataset;
	std::vector<std::string> classes;
	
	parse_csv(dataset, classes, path);
	std::cout << "Size of dataset: " << dataset.size() << std::endl;
	std::cout << "Number of classes: " << classes.size() << std::endl;

	std::cout << "Hello world" << std::endl;
}
