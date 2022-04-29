/*
	This file is the starting point of the program.
*/

#include <iostream>
#include <Windows.h>
#include <memory>

#include "System.h"

int main()
{
	auto system = std::make_unique<System>();
	HWND window = CreateWindow(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

	if (!system)
	{
		MessageBox(window, L"System, Memory allocate falied.", L"Error", MB_ICONHAND);
		return 0;
	}

	system->initialize();
	system->run();
	system->shutdown();
	
	return 0;
}