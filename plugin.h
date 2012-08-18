#ifndef _PLUGIN_H_
#define _PLGUIN_H_

#include <string>
#include "animal.h"

class Plugin
{
public:
    Plugin(const char* name)
		: m_name(name), m_pSoModule(NULL), m_pDestroy(NULL), m_pInterface(NULL)
    {}

    ~Plugin()
    {}

public:

    bool load();

    void unload();

    IBaseInterface* getInterface(){
        return m_pInterface;
    }
	
private:
	void cleanup();

private:
    std::string m_name;

    void * m_pSoModule;
	DestroyInterfacePtr m_pDestroy;
	
    IBaseInterface* m_pInterface;
};

#endif//_PLUGIN_H_
