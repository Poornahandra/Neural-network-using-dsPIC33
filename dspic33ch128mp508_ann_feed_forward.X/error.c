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
#include "error.h"

#if ENABLE_LEARNING == 1

void Error_Calculate(void)
{
    uint16_t i;
    for(i=0;i<TOTAL_OUTPUT_NEURONS;i++)
    {
        error[i] = expectedOutput[i] - outputNeuron[i].activatedOutput;
    }
    
    return;
}
#endif

