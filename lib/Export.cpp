#include "Plugin.hpp"

#define EXPORT __declspec(dllexport)
#define C_EXPORT extern "C" EXPORT

#ifdef WANNABECOM
C_EXPORT IUnknownLocal *GetPlugin()
{
	static CPlugin Plugin;
	return (IUnknownLocal*)&Plugin;
};
#else
C_EXPORT IPlugin *GetPlugin()
{
	static CPlugin Plugin;
	return &Plugin;
};
#endif