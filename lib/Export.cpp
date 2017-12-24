#include "Plugin.hpp"

#define EXPORT __declspec(dllexport)
#define C_EXPORT extern "C" EXPORT

C_EXPORT IPlugin *GetPlugin()
{
	static CPlugin Plugin;
	return &Plugin;
};