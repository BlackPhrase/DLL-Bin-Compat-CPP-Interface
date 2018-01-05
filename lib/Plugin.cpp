#include <cstdio>
#include "Plugin.hpp"

//IUnknownLocal::~IUnknownLocal() = default;

void CPlugin::Init()
{
	printf("Plugin init...\n");
};

void CPlugin::Shutdown()
{
	printf("Plugin shutdown...\n");
};