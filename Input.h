#pragma once

#include <windows.h>

#define DIRECTINPUT_VERSION  0x0800//DirectInputのバージョン指定
#include <dinput.h>

#include <wrl.h>

class Input
{
public://メンバ関数
	//初期化
	void Initialize(HINSTANCE hinstance,HWND hwnd);
	//更新
	void Update();

	
	bool PushKey(BYTE keyNumber);

	bool TriggerKey(BYTE keyNumber);

	template <class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

private:
	// キーボードデバイスの生成
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;

	BYTE key[256] = {};

	BYTE keyPre[256] = {};

};

