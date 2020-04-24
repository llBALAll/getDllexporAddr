#include <Windows.h>
#include <iostream>


int main (int argc, char** argv) {
	
	HMODULE hDll;
	FARPROC dllExportAddr;
	
	
	if (argc != 3) {
		std::cout << "\n  This program returns the address of a dll export (function/variable) loaded in RAM\n";
		std::cout << "    Usage: " << argv[0] << " <Dll Name> <Export Name> \n";
		return EXIT_FAILURE;
	}

	hDll = LoadLibrary (argv[1]);
	if (hDll == NULL) {
		printf("Error => could not load dll!\n");
		return EXIT_FAILURE;
	}

	dllExportAddr = GetProcAddress (hDll, argv[2]);
	if (dllExportAddr == NULL) {
		printf("Error => could not find this dll export!\n");
		return EXIT_FAILURE;
	}

	std::cout << "\n  The address of < " << argv[2] << " > in < " << argv[1] << " > is: 0x" << std::hex << std::uppercase << (DWORD64)dllExportAddr << std::endl;

	return EXIT_SUCCESS;
}
