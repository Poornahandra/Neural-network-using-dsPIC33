/*
 * File:   error.c
 * Author: I20885
 *
 * Created on April 23, 2023, 3:29 PM
 */


#include <xc.h>
#include "stdint.h"
#include "neural_network_config.h"
#include "neuron_types.h"
#include "data.h"
static int errorTotal=0;
void calculateError(void)
{
    uint16_t i;
    for(i=0;i<TOTAL_OUTPUT_NEURONS;i++)
    {
        error[i] = expectedOutput[i] - outputNeuron[i].activatedOutput;
    }
    
    return;
}
