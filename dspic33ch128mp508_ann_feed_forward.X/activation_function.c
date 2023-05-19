#include <math.h>
#include "neural_network_config.h"
double Activation_Function(double nonActivatedInput)
{
    double result;
#if ACTIVATION_FUNCTION == MC_CULLOCH
    if(nonActivatedInput>=1)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
#endif
#if ACTIVATION_FUNCTION == SIGMOIDAL    
    result = (1/(1+exp(-1*EXP_CONSTANT*nonActivatedInput)));
#endif
    return result;
}


double Derived_Activation_Function(double input)
{
    double result = input*(1-input);
    
    return result;
}
