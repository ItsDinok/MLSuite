# Explanations

This will be an  attempt to explain all of the ML models implemented in this repository, as well as the subtypes that have been implemented. The basic list is:

* Isolation Forest
* Logistic Regression

With plans to add:

* Multilayer perceptron
* Linear SVC
* Decision trees
* Random forests
* Naive Bayes
* k-Nearest Neighbour

## Isolation forest

Isolation forest is a primary anomaly detection algorithm. It works by taking a small subset of the dataset, in this case D, and recursively building a number of binary trees with the data. At each split a random feature is selected, and a random value is selected between the minimum and maximum value of that feature; all data points less than that value are passed to the left child node, all data points greater than or equal to are passed to the right child node. Isolation forest works on the belief that anomalies can be isolated with shorter paths, so the path length is passed into a scoring function and that is averaged across each tree to determine the probability that a sample is anomalous. 0.5 is likely not anomalous, 1 is likely anomalous.

It takes the contamination factor, c, which is the approximate amount of the dataset that is anomalous.

Scoring function and diagrams below:


## Logistic regression

Logistic regression uses a sigmoid function to map a combination of input features to a probability between 0 and 1, this probability corresponds to its position on the sigmoid curve. It does this by computing the sum of all input features and adding a bias term to them.

Diagrams below:

## Utility Functions

The utility functions are unsung heroes of this project, everything is implemented from scratch, so all file I/O and scoring functions need to be implemented from zero.

### CSV Parsing

This project uses a custom CSV parser which assumes all rows contain all data, all values are separated by commas and all rows are separated by a newline. It separates an output class from the rest of the features and appends them both to their respective vectors.

### Train/Test Splitter

This is a basic implementation of the same function that can be found within sklearn, it takes a number of references to vectors, a reference to the input vectors, and a proportion. It shuffles the data and splits them neatly into the train/test vectors.

### Set Shuffler

This shuffles vectors in place, keeping a 1:1 positional relation between X and Y datasets. This can be massively improved in its current iteration.

### Normalise

This uses basic min/max scaling in order to ensure that all values within a dataset are on a similar scale, ensuring that it is ideal for machine learning. This could be branched into different normalisation methods, but it is not essential.

### Illegal zero handlers

There are currently two handlers for illegal zeros in the dataset, one removes them and one replaces them with the median value. These are chosen depending on the dataset and the model, and whichever approach would work best for the context.

### Accuracy calculator

This takes in the predictions and the truth and computes what the total proportion of predictions were correct. It does this via:

`Accuracy = correct predictions / total predictions`
