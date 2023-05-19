/*
 * File:   main.c
 * Author: I20885
 *
 * Created on April 21, 2023, 6:47 PM
 */

#include "feed_forward.h"
#include "data.h"
#include "learningProcess.h"
#include <stdint.h>
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/uart/uart1.h"


void setTrainingSet(void)
{
    trainingInputSet[0][0] = 1;
    trainingInputSet[0][1] = 1;
    
    trainingInputSet[1][0] = 1;
    trainingInputSet[1][1] = 0;
    
    trainingInputSet[2][0] = 0;
    trainingInputSet[2][1] = 1;
    
    trainingInputSet[3][0] = 0;
    trainingInputSet[3][1] = 0;
    
    trainingOutputSet[0][0] = 0;
    trainingOutputSet[1][0] = 1;
    trainingOutputSet[2][0] = 1;
    trainingOutputSet[3][0] = 0;
}


void setBias(void)
{
    hiddenNeuron[0].bias = 0.8;
    hiddenNeuron[1].bias = -0.1;
    outputNeuron[0].bias = 0.3;
}

void setInitialWeights(void)
{
    hiddenNeuron[0].weight[0] = 0.5;
    hiddenNeuron[0].weight[1] = 0.4;
    
    hiddenNeuron[1].weight[0] = 0.9;
    hiddenNeuron[1].weight[1] = 1.0;
    
    outputNeuron[0].weight[0] = -1.2;
    outputNeuron[0].weight[1] = 1.1;
}

int main(void) {
    uint16_t epochRepeat = 5000,i;
    SYSTEM_Initialize();
    setBias();
    setInitialWeights();
    setTrainingSet();
    
    printf("Before training: Provide inputs\r\n");
    input[0] = (Serial.Read() == 48)?0:1;
    input[1] = (Serial.Read() == 48)?0:1;
    feed_forward();
    printf("%f\r\n",outputNeuron[0].activatedOutput);
    
    
    for(i=0;i<epochRepeat;i++)
    {
        while(currentLearningState != EPOCH_COMPLETE)
        {
            LearningProcess();
        }

        currentLearningState = START_EPOCH; 
    }
    
    
    
    while(1)
    {
        printf("After Training: Provide inputs\r\n");
        input[0] = (Serial.Read() == 48)?0:1;
        input[1] = (Serial.Read() == 48)?0:1;
        feed_forward();
        printf("%f\r\n",outputNeuron[0].activatedOutput);
    }
    
    //Implement stop condition
    
    return 0;
}
