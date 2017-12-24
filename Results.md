### Version #1

struct IUnknown
{
	virtual destructor = default;
}

struct IClass : public IUnknown
{
	// methods only, no destructor
};

class CClass : public IClass
{
	// methods impls
};

**Result:**
* Works fine when both app and lib are using the same compiler (MSVC-only/MinGW-only);
* MinGW app and MSVC lib crashes; (TODO: should check again);
* MSVC app and MinGW lib crashes; (TODO: should check again);

### Version #2

struct IClass
{
	// methods
protected:
	virtual destructor = default;
};

class CClass : public IClass
{
	// methods impls
};

**Result:**
* Works fine when both app and lib are using the same compiler (MSVC-only/MinGW-only);
* MinGW app and MSVC lib works fine;
* MSVC app and MinGW lib - some methods didn't get called but works;