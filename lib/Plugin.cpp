#include <cstdio>
#include "Plugin.hpp"

#ifdef USE_NAMESPACES
namespace pluginspace
{
#endif

//IUnknownLocal::~IUnknownLocal() = default;

void CPlugin::Init()
{
	printf("Plugin init...\n");
};

void CPlugin::Shutdown()
{
	printf("Plugin shutdown...\n");
};

#ifdef USE_NAMESPACES
}; // namespace pluginspace
#endif