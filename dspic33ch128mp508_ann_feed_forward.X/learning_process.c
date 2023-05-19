/*
 * File:   learningProcess.c
 * Author: I20885
 *
 * Created on April 24, 2023, 5:56 PM
 */
#include <stdint.h>
#include "learning_process.h"
#include "feed_forward.h"
#include "back_propagation.h"
#include "neural_network_config.h"
#include "data.h"
#include "error.h"

#if ENABLE_LEARNING == 1

enum LEARNING_STATE currentLearningState = EPOCH_START;

void Learning_Process_Start(void) 
{
    static uint8_t setIndex;
    switch(currentLearningState)
    {
        case EPOCH_START:
            setIndex = 0;
            currentLearningState = TRAINING_SET_UPDATE;
            break;
        case TRAINING_SET_UPDATE:
            if(setIndex < EPOCH_SIZE)
            {
                input[0] = trainingInputSet[setIndex][0];
                input[1] = trainingInputSet[setIndex][1];
                expectedOutput[0] = trainingOutputSet[setIndex][0];
                setIndex++;
                currentLearningState = FEED_FORWARD;
            }
            else
            {
                currentLearningState = EPOCH_COMPLETE;
            }
            
            break;
        case FEED_FORWARD:
                Feed_Forward_Start();
                currentLearningState = ERRORS_CALCULATE;
            break;
        case ERRORS_CALCULATE:
                Error_Calculate();
                currentLearningState = BACK_PROPOGATION;
            break;
        case BACK_PROPOGATION:
                Back_Propagation_Start();
                currentLearningState = TRAINING_SET_UPDATE;
            break;
        case EPOCH_COMPLETE:
        default:
            break;
            
    }
    return;
}
#endif
