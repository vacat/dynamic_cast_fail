#include "animal.h"

IBaseInterface::~IBaseInterface()
{}
	
IAnimal::~IAnimal()
{ }

IBird::~IBird()
{ }

void IBird::fly()
{
    std::cout << "I can fly\n";
}
