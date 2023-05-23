#include <stdlib.h>
#include "../neural_network_config/neural_network_config.h"
#include "data.h"
#include "randomize.h"


void Randomize_Weights(uint16_t seed)
{
    int i,j;
    srand(seed);
    for(i=0;i<TOTAL_HIDDEN_NEURONS;i++)
    {
        for(j=0;j<TOTAL_INPUTS;j++)
        {
            hiddenNeuron[i].weight[j] = rand()%RANDOM_LENGTH;
            hiddenNeuron[i].weight[j] /= RANDOM_LENGTH;
        }
    }
    
    for(i=0;i<TOTAL_OUTPUT_NEURONS;i++)
    {
        for(j=0;j<TOTAL_HIDDEN_NEURONS;j++)
        {
            outputNeuron[i].weight[j] = rand()%RANDOM_LENGTH;
            outputNeuron[i].weight[j] /= RANDOM_LENGTH;
        }
    }
}

void Randomize_Bias(uint16_t seed)
{
    int i;
    for(i=0;i<TOTAL_HIDDEN_NEURONS;i++)
    {
        hiddenNeuron[i].bias = rand()%RANDOM_LENGTH;
        hiddenNeuron[i].bias /= RANDOM_LENGTH;
    }
    
    for(i=0;i<TOTAL_OUTPUT_NEURONS;i++)
    {
        outputNeuron[i].bias = rand()%RANDOM_LENGTH;
        outputNeuron[i].bias /= RANDOM_LENGTH;
    }
}

