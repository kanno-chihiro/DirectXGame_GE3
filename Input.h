#pragma once

#include <windows.h>


class Input
{
public://ƒƒ“ƒoŠÖ”
	//‰Šú‰»
	void Initialize(HINSTANCE hinstance,HWND hwnd);
	//XV
	void Update();

	ComPtr<IDirectInput8> directInput;

};

