#include <iostream>
#include <math.h>
#include <cstdio>
#include <unistd.h>
#include <cstdlib>

using namespace std;

const float ALPHA=0.001;
const float THRESHOLD=0.50;
const int EPOCHS=2000;
const int NUM_FEATURES=2;
const int NUM_DATA_POINTS=4;
const int NUM_OUTPUT = 1;

int main(){
    int data[NUM_DATA_POINTS][NUM_FEATURES] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    int labels[NUM_DATA_POINTS] = {0, 1, 1, 1};     // AND GATE
    int prediction[NUM_DATA_POINTS] = {-1, -1, -1, -1};
    float perceptron_pred[NUM_DATA_POINTS] = {-1, -1, -1, -1};
    float weights[NUM_FEATURES][NUM_OUTPUT];

    for (int i =0; i < NUM_FEATURES; i ++) {
        for (int j = 0; j < NUM_OUTPUT; j ++) {
            weights[i][j] = float(rand()) / (float)(RAND_MAX);
        }
    }

    for (int i = 0; i < NUM_FEATURES ; i ++) {
        for (int j = 0; j < NUM_OUTPUT; j ++) {
            cout << "(" << i << "," << j << ") = " << weights[i][j] << endl;
        }
    }

    for(int each_epoch = 0; each_epoch < EPOCHS; each_epoch ++){
        for(int d = 0; d < NUM_DATA_POINTS; d ++){
            float perceptron_output = 0.0;
            for (int i = 0; i < NUM_FEATURES; i ++){
                for(int j = 0; j < NUM_OUTPUT; j ++){
                    perceptron_output += data[d][i] * weights[i][j];
                }
            }
            int perceptron_prediction;
            if (perceptron_output >= THRESHOLD){
                perceptron_prediction = 1;
            }else{
                perceptron_prediction = 0;
            }
            prediction[d] = perceptron_prediction;
            perceptron_pred[d] = perceptron_output;
            for (int i = 0; i < NUM_FEATURES; i ++) {
                for (int j = 0; j < NUM_OUTPUT; j ++) {
                    weights[i][j] += ALPHA * (labels[d] - perceptron_output) * data[d][i];
                }
            }
        }
    }

    for (int i =0; i < NUM_DATA_POINTS; i ++) {
        cout << "perceptron[i] = " << perceptron_pred[i] << " prediction[i] = " << prediction[i] << " actual[i] = " << labels[i] << endl;
    }

    for (int i = 0; i < NUM_FEATURES; i ++) {
        for (int j = 0; j < NUM_OUTPUT; j ++){
            cout << weights[i][j] << endl;
        } 
    }

    return 0;
}