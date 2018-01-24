#pragma once

#ifdef WANNABECOM

#ifdef WANNABECOM_INLINE_DESTRUCTOR
struct IUnknownLocal
{
	virtual ~IUnknownLocal() = default;
};
#else
struct IUnknownLocal
{
	//virtual ~IUnknownLocal() = 0;
	virtual void Release() = 0;
};
#endif

struct IPlugin : public IUnknownLocal
{
	virtual void Init() = 0;
	virtual void Shutdown() = 0;
};

using pfnGetPlugin = IUnknownLocal *(*)();
#else
struct IPlugin
{
	virtual void Init() = 0;
	virtual void Shutdown() = 0;
protected:
	virtual ~IPlugin() = default;
};

using pfnGetPlugin = IPlugin *(*)();
#endif