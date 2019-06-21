### Version #1

```cpp
struct IUnknown
{
	virtual destructor = default;
}

struct IClass : public IUnknown
{
	// methods decls
};

class CClass : public IClass
{
	// methods impls
};
```

**Result:**
* Works fine when both app and lib are using the same compiler (MSVC-only/MinGW-only);
* MinGW app and MSVC lib calls some methods and crashes;
* MSVC app and MinGW lib simply crashes;

### Version #2

```cpp
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
```

**Result:**
* Works fine when both app and lib are using the same compiler (MSVC-only/MinGW-only);
* MinGW app and MSVC lib works fine;
* MSVC app and MinGW lib - some methods didn't get called but works;

### Version #3

```cpp
struct IUnknown
{
	virtual void Release() = 0;
}

struct IClass : public IUnknown
{
	void Release() override
	{
		delete this; // MSVC crashes here if allocated statically
	};
	
	// other methods decls
};

class CClass : public IClass
{
	// methods impls
};
```

**Result:**
* Works fine when both app and lib are using the same compiler (MSVC-only/MinGW-only);
* MinGW app and MSVC works fine(!);
* MSVC app and MinGW works fine(!);

### Version #4

```cpp
namespace pluginspace
{

struct IUnknown
{
	virtual void Release() = 0;
}

struct IClass : public IUnknown
{
	void Release() override
	{
		delete this; // MSVC crashes here if allocated statically
	};
	
	// other methods decls
};

class CClass : public IClass
{
	// methods impls
};

}; // namespace pluginspace
```

**Result:**
* Works fine when both app and lib are using the same compiler (MSVC-only/MinGW-only);
* MinGW app and MSVC works fine(!);
* MSVC app and MinGW works fine(!);
* The reason for that is that the app still receives a valid pointer to a virtual interface 
and calls its methods by calling a "base pointer" + "offset of required method in vtable" 
so it doesn't matter whether or not the class is mangled and how;