#include "helper.h"

double Unactivated_Result(double input[], double weight[], double bias, uint16_t totalInputs) 
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
