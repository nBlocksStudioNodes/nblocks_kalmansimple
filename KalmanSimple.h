#ifndef __NB_FLEXCOUNTER
#define __NB_FLEXCOUNTER

#include "nworkbench.h"

class nBlock_FlexCounter: public nBlockSimpleNode<1> {

public:
    nBlock_FlexCounter(uint32_t maxvalue, uint32_t minvalue, uint32_t step, uint32_t MODE);
    void triggerInput(nBlocks_Message message);
	void endFrame(void);

    uint32_t _count;
	uint32_t mode;
    uint32_t _step;
    uint32_t _minvalue;
    uint32_t _maxvalue;

private:
	
	uint8_t  _direction;
    uint32_t newValueFLAG;	
};

#endif