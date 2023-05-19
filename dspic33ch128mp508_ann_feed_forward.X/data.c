#include "neural_network_config.h"
#include "neuron_types.h"


//Input data
double input[TOTAL_INPUTS];

//Hidden layer neuron data
hidden_neuron_t hiddenNeuron[TOTAL_HIDDEN_NEURONS];

//Output layer neuron data
output_neuron_t outputNeuron[TOTAL_OUTPUT_NEURONS];

//storage if learning is enabled
#if ENABLE_LEARNING == 1
double trainingInputSet[EPOCH_SIZE][TOTAL_INPUTS];
double trainingOutputSet[EPOCH_SIZE][TOTAL_OUTPUT_NEURONS];

double expectedOutput[TOTAL_OUTPUT_NEURONS];
double error[TOTAL_OUTPUT_NEURONS];
#endif
