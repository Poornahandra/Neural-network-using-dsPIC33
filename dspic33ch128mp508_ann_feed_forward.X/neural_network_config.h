  
#ifndef NEURAL_NETWORK_CONFIG_H
#define	NEURAL_NETWORK_CONFIG_H

#define MC_CULLOCH 1
#define SIGMOIDAL 2


//Input layer configurations
#define TOTAL_INPUTS 2

//Hidden layer configurations
#define TOTAL_HIDDEN_NEURONS 2

//Output layer configurations
#define TOTAL_OUTPUT_NEURONS 1

//Functions
#define ACTIVATION_FUNCTION SIGMOIDAL
#if ACTIVATION_FUNCTION == SIGMOIDAL
#define EXP_CONSTANT 1 
#endif

//Learning parameters
#define ENABLE_LEARNING
#define LEARNING_RATE 1
#define EPOCH_SIZE 4
#define ENABLE_BIAS_ADJUST 1

#endif	/* NEURAL_NETWORK_CONFIG_H */

