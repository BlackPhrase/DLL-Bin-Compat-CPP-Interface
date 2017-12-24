#pragma once

#ifdef WANNABECOM
struct IUnknownLocal
{
	virtual ~IUnknownLocal() = default;
};

struct IPlugin : public IUnknownLocal
{
	virtual void Init() = 0;
	virtual void Shutdown() = 0;
};
#else
struct IPlugin
{
	virtual void Init() = 0;
	virtual void Shutdown() = 0;
protected:
	virtual ~IPlugin() = default;
};
#endif

using pfnGetPlugin = IPlugin *(*)();