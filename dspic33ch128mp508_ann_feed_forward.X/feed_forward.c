/*
 * File:   feed_forward.c
 * Author: I20885
 *
 * Created on April 21, 2023, 6:48 PM
 */

#include "data.h"
#include "helper.h"
#include "neuron_types.h"
#include "activation_function.h"
#include <stdint.h>

void feed_forward(void) 
{
    double hiddenOutputs[TOTAL_HIDDEN_NEURONS];
    uint16_t i;
    for(i=0;i<TOTAL_HIDDEN_NEURONS;i++)
    {
        //neuron i in hidden layer
        hiddenNeuron[i].output = VOUT(input, hiddenNeuron[i].weight, hiddenNeuron[i].bias,TOTAL_INPUTS);
        hiddenNeuron[i].activatedOutput = PHI(hiddenNeuron[i].output);
        hiddenOutputs[i] = hiddenNeuron[i].activatedOutput;
    }

    for(i=0;i<TOTAL_OUTPUT_NEURONS;i++)
    {
        //neuron i in output layer
        outputNeuron[i].output = VOUT(hiddenOutputs, outputNeuron[i].weight, outputNeuron[i].bias,TOTAL_HIDDEN_NEURONS);
        outputNeuron[i].activatedOutput = PHI(outputNeuron[i].output);
    }
}
