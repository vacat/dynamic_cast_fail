#ifndef _LIB_DOG_H_
#define _LIB_DOG_H_

#include "animal.h"

class Dog : public IAnimal 
{
public:
    Dog(): IAnimal("dog")
    {}

    virtual ~Dog()
    {}

public:
	virtual void doSomething();
	
	void doBarking(){
		std::cout << "dog barking~~\n";
	}
};

extern "C" IBaseInterface* createInterface()
{
    return new Dog;
}

extern "C" void* destroyInterface(IBaseInterface* pInterface){
	delete pInterface;
	pInterface = NULL;
}

#endif//_LIB_DOG_H_
