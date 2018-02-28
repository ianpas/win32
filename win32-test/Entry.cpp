#include "stdafx.h"


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow)
{
	Glorious::Application app{ hInstance,nCmdShow,L"Window",800,600 };
	auto run = []()
	{

	};
	app.Run(run);

	return 0;
}