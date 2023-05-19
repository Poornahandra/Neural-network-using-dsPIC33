
#ifndef NEURON_TYPES_H
#define	NEURON_TYPES_H

#include "neural_network_config.h"

enum LAYER 
{
    HIDDEN_LAYER1,
    OUTPUT_LAYER
};

//Hidden layer
typedef struct {
    double weight[TOTAL_INPUTS];
    double bias;
    double output;
    double activatedOutput;
#ifdef ENABLE_LEARNING
    double doe;
    double deltaWeight[TOTAL_INPUTS];
    double deltaBias;
#endif
} hidden_neuron_t;

//Output layer
typedef struct {
    double weight[TOTAL_HIDDEN_NEURONS];
    double bias;
    double output;
    double activatedOutput;
#ifdef ENABLE_LEARNING
    double doe;
    double deltaWeight[TOTAL_HIDDEN_NEURONS];
    double deltaBias;
#endif
} output_neuron_t;
#endif	/* NEURON_TYPES_H */

