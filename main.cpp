#include "animal.h"
#include "plugin.h"

int main(int argc, char** argv)
{
	Plugin plugin("libdog.so");
	if (!plugin.load()){
		std::cerr << "!!!plugin load fail!!!\n";
		return -1;
	}
	
	int ret = 0;
	
	IBaseInterface* pInterface = plugin.getInterface();
	IAnimal *pAnimal = dynamic_cast<IAnimal*>(pInterface);
	if (pAnimal){
		pAnimal->doSomething();
	} else {
		std::cerr << "can't cast from baseinterface to animal\n";
		ret = -2;
	}
	
	plugin.unload();
	return ret;
}


