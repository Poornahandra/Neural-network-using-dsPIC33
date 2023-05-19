#ifndef LEARNING_PROCESS_H
#define	LEARNING_PROCESS_H

#include "neural_network_config.h"

#if ENABLE_LEARNING == 1

enum LEARNING_STATE 
{
    EPOCH_START,
    TRAINING_SET_UPDATE,
    FEED_FORWARD,
    ERRORS_CALCULATE,
    BACK_PROPOGATION,
    EPOCH_COMPLETE
};
extern enum LEARNING_STATE currentLearningState;

void Learning_Process_Start(void);

#endif

#endif	/* LEARNING_PROCESS_H */

