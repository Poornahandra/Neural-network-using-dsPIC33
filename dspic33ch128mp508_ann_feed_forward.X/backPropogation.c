/*
 * File:   backPropogation.c
 * Author: I20885
 *
 * Created on April 23, 2023, 4:32 PM
 */

#include "neural_network_config.h"
#include "data.h"
#include <stdint.h>
#include <xc.h>

void backPropogation(void) 
{
    uint16_t i,j;
    
    //Calculate weight adjustments
    for(i=0;i<TOTAL_OUTPUT_NEURONS;i++)
    {
        outputNeuron[i].doe = EXP_CONSTANT*(expectedOutput[i]-outputNeuron[i].activatedOutput)*(outputNeuron[i].activatedOutput)*(1-outputNeuron[i].activatedOutput);
        for(j=0;j<TOTAL_HIDDEN_NEURONS;j++)
        {
            hiddenNeuron[j].doe = EXP_CONSTANT*(outputNeuron[i].weight[j])*(outputNeuron[i].doe)*(hiddenNeuron[j].activatedOutput)*(1-hiddenNeuron[j].activatedOutput);
            outputNeuron[i].deltaWeight[j] = LEARNING_RATE*(outputNeuron[i].doe)*(hiddenNeuron[j].activatedOutput);
            outputNeuron[i].weight[j] = outputNeuron[i].weight[j] + outputNeuron[i].deltaWeight[j];
        }
#if (ENABLE_BIAS_ADJUST == 1)
        outputNeuron[i].deltaBias = LEARNING_RATE*(-1)*(outputNeuron[i].doe);
        outputNeuron[i].bias = (outputNeuron[i].bias) + (outputNeuron[i].deltaBias);
#endif        
    }
    
    //Calculate delta weight
    for(i=0;i<TOTAL_HIDDEN_NEURONS;i++)
    {
        for(j=0;j<TOTAL_INPUTS;j++)
        {
            hiddenNeuron[i].deltaWeight[j] = LEARNING_RATE*(input[j])*(hiddenNeuron[i].doe);
            hiddenNeuron[i].weight[j] = hiddenNeuron[i].weight[j] + hiddenNeuron[i].deltaWeight[j];
        }
#if (ENABLE_BIAS_ADJUST == 1)
        hiddenNeuron[i].deltaBias = LEARNING_RATE*(-1)*(hiddenNeuron[i].doe);
        hiddenNeuron[i].bias = (hiddenNeuron[i].bias)+(hiddenNeuron[i].deltaBias);
#endif
    }
    return;
}
