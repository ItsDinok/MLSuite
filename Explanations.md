# Explanations

This will be an  attempt to explain all of the ML models implemented in this repository, as well as the subtypes that have been implemented. The basic list is:

* Isolation Forest
* Logistic Regression

With plans to add:

* Multilayer perceptron
* Linear SVC
* Decision trees
* Random forests
* Naive bayes

## Isolation forest

Isolation forest is a primary anomaly detection algorithm. It works by taking a small subset of the dataset, in this case D, and recursively building a number of binary trees with the data. At each split a random feature is selected, and a random value is selected between the minimum and maximum value of that feature; all data points less than that value are passed to the left child node, all data points greater than or equal to are passed to the right child node. Isolation forest works on the belief that anomalies can be isolated with shorter paths, so the path length is passed into a scoring function and that is averaged across each tree to determine the probability that a sample is anomalous. 0.5 is likely not anomalous, 1 is likely anomalous.

It takes the contamination factor, c, which is the approximate amount of the dataset that is anomalous.

Scoring function and diagrams below:


## Logistic regression
