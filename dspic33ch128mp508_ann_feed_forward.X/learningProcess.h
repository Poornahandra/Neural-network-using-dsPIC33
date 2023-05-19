
#ifndef LEARNING_PROCESS_H
#define	LEARNING_PROCESS_H

enum LEARNING_STATE 
{
    START_EPOCH,
    UPDATE_TRAINING_SET,
    FEED_FORWARD,
    CALCULATE_ERRORS,
    BACK_PROPOGATION,
    EPOCH_COMPLETE
};
extern enum LEARNING_STATE currentLearningState;

void LearningProcess(void);

#endif	/* LEARNING_PROCESS_H */

