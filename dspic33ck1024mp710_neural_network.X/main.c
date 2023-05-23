/*
 * File:   main.c
 * Author: I20885
 *
 * Created on April 21, 2023, 6:47 PM
 */
#include <stdint.h>

#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/uart/uart1.h"

#include "neural_network/feed_forward.h"
#include "neural_network/data.h"
#include "neural_network/learning_process.h"
#include "neural_network/randomize.h"

#include "training_set/trainingData.h"

#define EPOCH_REPEAT 500UL



int main(void) {
    uint16_t epochRepeatCount;
    SYSTEM_Initialize();
    Randomize_Weights(1234);
    Randomize_Bias(5678);
    trainingDataSet();
    
    printf("Before training:\r\nPlease Provide %d binary inputs\r\n",TOTAL_INPUTS);
    input[0] = (Serial.Read() == 48)?0:1;
    input[1] = (Serial.Read() == 48)?0:1;
    Feed_Forward_Start();
    printf(" -> %f\r\n",outputNeuron[0].activatedOutput);
    
    
    for(epochRepeatCount=0;epochRepeatCount<EPOCH_REPEAT;epochRepeatCount++)
    {
        while(currentLearningState != EPOCH_COMPLETE)
        {
            Learning_Process_Start();
        }

        currentLearningState = EPOCH_START; 
    }
    
    while(1)
    {
        printf("After Training:\r\nPlease Provide %d binary inputs\r\n",TOTAL_INPUTS);
        input[0] = (Serial.Read() == 48)?0:1;
        input[1] = (Serial.Read() == 48)?0:1;
        Feed_Forward_Start();
        printf(" -> %f\r\n",outputNeuron[0].activatedOutput);
    }
    
    return 0;
}
