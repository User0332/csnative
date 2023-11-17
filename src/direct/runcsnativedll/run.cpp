#include "Windows.h"
#include <string>
#include <iostream>
#include <codecvt>
#include <locale>

int main(int argc, char** argv) // does not support command line args yet
{
	HMODULE dll = LoadLibrary(
		argv[0]
	);

	if (!dll)
	{
		std::cerr << "Could not load application." << std::endl;
		
		return 1;
		
	}

	void (__cdecl *func)() = (void (__cdecl *)()) GetProcAddress(dll, "csnative_entrypoint");

	if (!func)
	{
		std::cerr << "Could not resolve entrypoint." << std::endl;

		return 1;
	}

	func();

	return 0;
}