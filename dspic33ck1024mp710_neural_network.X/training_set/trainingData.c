#include "../neural_network/data.h"

void trainingDataSet(void)
{
    
    trainingInputSet[0][0] = 1;
    trainingInputSet[0][1] = 1;
    
    trainingInputSet[1][0] = 1;
    trainingInputSet[1][1] = 0;
    
    trainingInputSet[2][0] = 0;
    trainingInputSet[2][1] = 1;
    
    trainingInputSet[3][0] = 0;
    trainingInputSet[3][1] = 0;
    
    trainingOutputSet[0][0] = 1;
    trainingOutputSet[1][0] = 1;
    trainingOutputSet[2][0] = 1;
    trainingOutputSet[3][0] = 0;
}