#include "FlexCounter.h"
#include "SimpleKalmanFilter.h"

nBlock_KalmanSimple::nBlock_KalmanSimple(float e_mea, float e_est, float q):
	_kalman(e_mea, e_est, q) {
}

void nBlock_KalmanSimple::triggerInput(nBlocks_Message message){
    if (message.inputNumber == 0) {         // new feedback-value at Input1 (Schematic Input 2)
        if (message.dataType == OUTPUT_TYPE_FLOAT) {
            _input = message.floatValue;      
            newValueFLAG = 1;
        }
    }
}	

void nBlock_KalmanSimple::endFrame(void) {
	if(newValueFLAG){
		newValueFLAG = 0;
		_estimated_value = _kalman.updateEstimate(_input);
		output[0] = _estimated_value;
		available[0] = 1;
	}	
}
