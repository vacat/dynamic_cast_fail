#include "plugin.h"
#include "animal.h"
#include <dlfcn.h>

bool Plugin::load()
{
    m_pSoModule = dlopen(m_name.c_str(), RTLD_NOW);
    if (!m_pSoModule){
        std::cerr << "dlopen return " << dlerror() << "\n";
        return false;
    }

    CreateInterfacePtr pCreate = (CreateInterfacePtr)dlsym(m_pSoModule, "createInterface");
    if (!pCreate){
        std::cerr << "dlsym return " << dlerror() << "\n";
		cleanup();
        return false;
    }
	
	m_pDestroy = (DestroyInterfacePtr)dlsym(m_pSoModule, "destroyInterface");
	if (!m_pDestroy){
        std::cerr << "dlsym return " << dlerror() << "\n";
		cleanup();
        return false;
	}
	
	m_pInterface = pCreate();
	if (!m_pInterface){
		std::cerr << "Can't create interface " << m_name << "\n";
		cleanup();
		return false;
	}

    return true;
}

void Plugin::unload()
{
	cleanup();
}

void Plugin::cleanup()
{
	if (m_pInterface){
		m_pDestroy(m_pInterface);
		m_pInterface = NULL;
	}
	
	if (m_pSoModule){
		dlclose(m_pSoModule);
		m_pSoModule = NULL;
	}
}



