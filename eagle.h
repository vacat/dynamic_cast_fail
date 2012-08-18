#ifndef _LIB_EAGLE_H_
#define _LIB_EAGLE_H_

#include "animal.h"

class Eagle : public IBird
{
public:
    Eagle() : IBird("eagle")
    {}

    virtual ~Eagle()
    {}

public:
    virtual void say();

    virtual void fly();
};

extern "C" IBaseInterface* createInterface(){
    return new Eagle;
}

extern "C" void* destroyInterface(IBaseInterface* pInterface){
	delete pInterface;
	pInterface = NULL;
}

#endif//_LIB_EAGLE_H_
