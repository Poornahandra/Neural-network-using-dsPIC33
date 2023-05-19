
#ifndef DATA_H
#define	DATA_H

#include "neuron_types.h"

extern double input[TOTAL_INPUTS];
extern double trainingInputSet[EPOCH_SIZE][TOTAL_INPUTS];
extern double trainingOutputSet[EPOCH_SIZE][TOTAL_OUTPUT_NEURONS];

extern hidden_neuron_t hiddenNeuron[TOTAL_HIDDEN_NEURONS];

extern output_neuron_t outputNeuron[TOTAL_OUTPUT_NEURONS];

//storage if learning is enabled
#ifdef ENABLE_LEARNING
extern double expectedOutput[TOTAL_OUTPUT_NEURONS];
extern double error[TOTAL_OUTPUT_NEURONS];
extern double epochOutput[EPOCH_SIZE][TOTAL_OUTPUT_NEURONS];
#endif

#endif	/* DATA_H */

