#pragma once

#include <windows.h>


class Input
{
public://メンバ関数
	//初期化
	void Initialize(HINSTANCE hinstance,HWND hwnd);
	//更新
	void Update();

	ComPtr<IDirectInput8> directInput;

};

