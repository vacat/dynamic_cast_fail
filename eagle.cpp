#include "eagle.h"

void Eagle::say()
{
    std::cout << "I am a eagle\n";
}

void Eagle::fly()
{
    say();
    IBird::fly();
}
