// NeuralNetworks.cpp : This file contains the 'main' function. Program execution begins and ends there.//

#include <iostream>
#include "MLP.h"

int main() {
    srand(time(NULL));
    rand();

    //test code - Segment Display Recognition System
    int epochs = 1000;
    MultiLayerPerceptron *sdrnn;
    
    sdrnn = new MultiLayerPerceptron({7,7,1});
    double MSE;
    // Dataset for the 7 to 1 network
    for (int i = 0; i < epochs; i++){
        MSE = 0.0;
        MSE += sdrnn->bp({1,1,1,1,1,1,0}, {0.05}); //0 pattern
        MSE += sdrnn->bp({0,1,1,0,0,0,0}, {0.15}); //1 pattern
        MSE += sdrnn->bp({1,1,0,1,1,0,1}, {0.25}); //2 pattern
        MSE += sdrnn->bp({1,1,1,1,0,0,1}, {0.35}); //3 pattern
        MSE += sdrnn->bp({0,1,1,0,0,1,1}, {0.45}); //4 pattern
        MSE += sdrnn->bp({1,0,1,1,0,1,1}, {0.55}); //5 pattern
        MSE += sdrnn->bp({1,0,1,1,1,1,1}, {0.65}); //6 pattern
        MSE += sdrnn->bp({1,1,1,0,0,0,0}, {0.75}); //7 pattern
        MSE += sdrnn->bp({1,1,1,1,1,1,1}, {0.85}); //8 pattern
        MSE += sdrnn->bp({1,1,1,1,0,1,1}, {0.95}); //9 pattern
    }
    MSE /= 10.0;
    cout << endl << "7 to 1  network MSE: " << MSE << endl;


    // Dataset for the 7 to 10 network
    delete(sdrnn);
    sdrnn = new MultiLayerPerceptron({7,7,10});
    
    for (int i = 0; i < epochs; i++){
        MSE = 0.0;
        MSE += sdrnn->bp({1,1,1,1,1,1,0}, {1,0,0,0,0,0,0,0,0,0}); //0 pattern
        MSE += sdrnn->bp({0,1,1,0,0,0,0}, {0,1,0,0,0,0,0,0,0,0}); //1 pattern
        MSE += sdrnn->bp({1,1,0,1,1,0,1}, {0,0,1,0,0,0,0,0,0,0}); //2 pattern
        MSE += sdrnn->bp({1,1,1,1,0,0,1}, {0,0,0,1,0,0,0,0,0,0}); //3 pattern
        MSE += sdrnn->bp({0,1,1,0,0,1,1}, {0,0,0,0,1,0,0,0,0,0}); //4 pattern
        MSE += sdrnn->bp({1,0,1,1,0,1,1}, {0,0,0,0,0,1,0,0,0,0}); //5 pattern
        MSE += sdrnn->bp({1,0,1,1,1,1,1}, {0,0,0,0,0,0,1,0,0,0}); //6 pattern
        MSE += sdrnn->bp({1,1,1,0,0,0,0}, {0,0,0,0,0,0,0,1,0,0}); //7 pattern
        MSE += sdrnn->bp({1,1,1,1,1,1,1}, {0,0,0,0,0,0,0,0,1,0}); //8 pattern
        MSE += sdrnn->bp({1,1,1,1,0,1,1}, {0,0,0,0,0,0,0,0,0,1}); //9 pattern
    }
    MSE /= 10.0;
    cout << "7 to 10 network MSE: " << MSE << endl;

    
    // Dataset for the 7 to 7 network
    delete(sdrnn);
    sdrnn = new MultiLayerPerceptron({7,7,7});

    for (int i = 0; i < epochs; i++){
        MSE = 0.0;
        MSE += sdrnn->bp({1,1,1,1,1,1,0}, {1,1,1,1,1,1,0}); //0 pattern
        MSE += sdrnn->bp({0,1,1,0,0,0,0}, {0,1,1,0,0,0,0}); //1 pattern
        MSE += sdrnn->bp({1,1,0,1,1,0,1}, {1,1,0,1,1,0,1}); //2 pattern
        MSE += sdrnn->bp({1,1,1,1,0,0,1}, {1,1,1,1,0,0,1}); //3 pattern
        MSE += sdrnn->bp({0,1,1,0,0,1,1}, {0,1,1,0,0,1,1}); //4 pattern
        MSE += sdrnn->bp({1,0,1,1,0,1,1}, {1,0,1,1,0,1,1}); //5 pattern
        MSE += sdrnn->bp({1,0,1,1,1,1,1}, {1,0,1,1,1,1,1}); //6 pattern
        MSE += sdrnn->bp({1,1,1,0,0,0,0}, {1,1,1,0,0,0,0}); //7 pattern
        MSE += sdrnn->bp({1,1,1,1,1,1,1}, {1,1,1,1,1,1,1}); //8 pattern
        MSE += sdrnn->bp({1,1,1,1,0,1,1}, {1,1,1,1,0,1,1}); //9 pattern
    }
    MSE /= 10.0;
    cout << "7 to 7  network MSE: " << MSE << endl << endl;

}
