#include <cstdlib>
#include <windows.h>
#include "IPlugin.hpp"

int main(int argc, char **argv)
{
	auto hPlugin{LoadLibrary("liblib")};
	
	if(!hPlugin)
		return EXIT_FAILURE;
	
	auto fnGetPlugin{(pfnGetPlugin)GetProcAddress(hPlugin, "GetPlugin")};
	
	if(!fnGetPlugin)
		return EXIT_FAILURE;
	
	auto pPlugin{fnGetPlugin()};
	
	if(!pPlugin)
		return EXIT_FAILURE;
	
	pPlugin->Init();
	
	pPlugin->Shutdown();
	
	system("pause");
	
	FreeLibrary(hPlugin);
	
	return EXIT_SUCCESS;
};