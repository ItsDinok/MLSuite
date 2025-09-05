# ML Suite

This is a series of implementations of common binary classifiers and anomaly detection algorithms that is done to both hone my understanding of these as I go into a PhD on machine learning, and to practice programming without LLM assistance, something I have come to rely upon heavily. I believe this is one of those projects that is never really going to be *done* and will be iteratively worked upon until I forget about it or rival sklearn (I will probably forget about it).

It is written entirely in C++ and uses no libraries other than those found within the g++ STL. It can be compiled with the attached makefile and should be fully cross-compatible. All of the tools peripheral to the models are also written in C++.

## Goals
This project broadly had three goals:

* Better understand ML models
* Create fast ML models
* Create memory-optimised ML models

I believe that it is pointless to build a poor performance ML model, and as such the minimum acceptable accuracy for each will be 0.75 on their respective dataset.

## Aspirational targets

If time or boredom allows I would love to implement:
* Model ensembles 
* Federated learning
* RNN
* CNN
* My own ML algorithm

These are all huge undertakings, however, so it is likely this will never come to pass.
