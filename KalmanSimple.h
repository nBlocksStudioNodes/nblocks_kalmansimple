#ifndef __NB_KALMANSIMPLE
#define __NB_KALMANSIMPLE

#include "nworkbench.h"

class nBlock_KalmanSimple: public nBlockSimpleNode<1> {

public:
    nBlock_KalmanSimple(float e_mea, float e_est, float q);
    void triggerInput(nBlocks_Message message);
	void endFrame(void);
    uint32_t newValueFLAG;

private:	
	float  _input;
    float _estimated_value;
    SimpleKalmanFilter _kalman;
};

#endif