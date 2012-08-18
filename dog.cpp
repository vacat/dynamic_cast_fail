#include "dog.h"
#include "plugin.h"

void Dog::doSomething(){
	sayHello();
	doBarking();
	
	Plugin plugin("libeagle.so");
	if (!plugin.load()){
		std::cerr << "!!!plugin load fail!!!\n";
		return;
	}
	
	IBaseInterface* pInterface = plugin.getInterface();
	IBird *pBird = dynamic_cast<IBird*>(pInterface);
	if (pBird){
		std::cout << "dog found a bird\n";
		pBird->fly();
	} else {
		std::cerr << "!!!Cast interface to bird fail, dog found nothing!!!\n";
	}
	
	plugin.unload();
	return;
}
