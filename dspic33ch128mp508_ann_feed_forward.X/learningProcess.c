/*
 * File:   learningProcess.c
 * Author: I20885
 *
 * Created on April 24, 2023, 5:56 PM
 */
#include <stdint.h>
#include "learningProcess.h"
#include "feed_forward.h"
#include "backPropogation.h"
#include "neural_network_config.h"
#include "data.h"
#include "error.h"

enum LEARNING_STATE currentLearningState = START_EPOCH;

void LearningProcess(void) 
{
    static uint8_t setIndex;
    switch(currentLearningState)
    {
        case START_EPOCH:
            setIndex = 0;
            currentLearningState = UPDATE_TRAINING_SET;
            break;
        case UPDATE_TRAINING_SET:
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
                feed_forward();
                currentLearningState = CALCULATE_ERRORS;
            break;
        case CALCULATE_ERRORS:
                calculateError();
                currentLearningState = BACK_PROPOGATION;
            break;
        case BACK_PROPOGATION:
                backPropogation();
                currentLearningState = FEED_FORWARD;
            break;
        case EPOCH_COMPLETE:
            
            break;
    }
    return;
}
