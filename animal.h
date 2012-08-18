#ifndef _LIB_ANIMAL_H_
#define _LIB_ANIMAL_H_

#include <string>
#include <iostream>

class IBaseInterface
{
public:
    IBaseInterface()
    {}

    virtual ~IBaseInterface() = 0;
};

typedef IBaseInterface* (*CreateInterfacePtr)();
typedef void (*DestroyInterfacePtr)(IBaseInterface* pIBaseInterface);

class IAnimal : public IBaseInterface
{
public:
    IAnimal(const char* name = "Animal") : m_name(name)
    {}

    virtual ~IAnimal() = 0;

	virtual void doSomething() = 0;
	
protected:
    void sayHello(){
    	std::cout << "Hello, i am a " << m_name << "\n";
    }

private:
    std::string m_name;
};

class IBird : public IAnimal
{
public:
    IBird(const char* name = "Bird") : IAnimal(name)
    {}

    virtual ~IBird() = 0;

    virtual void doSomething(){
    	fly();
    }

    virtual void fly();
};

#endif//_LIB_ANIMAL_H_
