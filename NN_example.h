#include <stdlib.h>
#include <math.h>

// define NN architecture
#define INPUT_SIZE 2
#define OUTPUT_SIZE 1
#define LEARNING_RATE 0.01
#define EPOCHS 10000

// leakyReLu activation function
double activation(double x) {
    return (x > 0) ? 1.0 : 0.0;
}

// weights and biases definition
double weights[INPUT_SIZE];
double bias;
