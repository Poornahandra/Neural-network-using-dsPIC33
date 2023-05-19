 
#ifndef ACTIVATION_FUNCTION_H
#define	ACTIVATION_FUNCTION_H

#include "neuron_types.h"
#include "neural_network_config.h"


double Activation_Function(double nonActivatedInput);
double Derived_Activation_Function(double Input);

#define PHI(x) Activation_Function(x)
#define dPHI(x) Derived_Activation_Function(x)
#define VOUT(w,x,y,z) Unactivated_Result(w,x,y,z)


#endif	/* ACTIVATION_FUNCTION_H */

