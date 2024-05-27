#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NN_example.h"

// Function to normalize the data
// Function to normalize the data
void normalize(double data[][INPUT_SIZE], int rows) {
    double max_values[INPUT_SIZE];
    
    // Find the maximum value for each feature
    for (int j = 0; j < INPUT_SIZE; j++) {
        max_values[j] = data[0][j];
        for (int i = 1; i < rows; i++) {
            if (data[i][j] > max_values[j]) {
                max_values[j] = data[i][j];
            }
        }
    }

    // Normalize each feature
    for (int j = 0; j < INPUT_SIZE; j++) {
        for (int i = 0; i < rows; i++) {
            data[i][j] /= max_values[j];
        }
    }
}


// Initialize the neural network
void initialize() {
    for (int i = 0; i < INPUT_SIZE; i++) {
        weights[i] = ((double)rand() / RAND_MAX) * 2 - 1; // Initialize weights randomly
    }
    bias = ((double)rand() / RAND_MAX) * 2 - 1; // Initialize bias randomly
}

// Feedforward propagation
double predict(double inputs[]) {
    double output = 0;
    for (int i = 0; i < INPUT_SIZE; i++) {
        output += weights[i] * inputs[i];
    }
    output += bias;
    return activation(output);
}

// Training
void train(double inputs[], double target) {
    double prediction = predict(inputs);
    double error = target - prediction;
    for (int i = 0; i < INPUT_SIZE; i++) {
        weights[i] += LEARNING_RATE * error * inputs[i];
    }
    bias += LEARNING_RATE * error;
}



