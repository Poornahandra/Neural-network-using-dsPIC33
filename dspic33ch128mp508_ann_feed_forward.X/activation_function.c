#include <math.h>
#include <stdint.h>
#include "neural_network_config.h"

double Activation_Function(double nonActivatedInput)
{
    return (1/(1+exp(-1*SIGMOID_EXP_CONSTANT*nonActivatedInput)));
}

double Derived_Activation_Function(double input)
{
    return input*(1-input);
}

double Unactivated_Result_Calculate(double input[], double weight[], double bias, uint16_t totalInputs) 
{    
    double result = 0;
    uint16_t i;
    for(i =0;i<totalInputs;i++)
    {
        result = result + (input[i] * weight[i]);
    }
    result = result - bias;
    
    return result;
}