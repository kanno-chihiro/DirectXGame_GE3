#pragma once

#include <windows.h>
#include <wrl.h>

#define DIRECTINPUT_VERSION  0x0800//DirectInputのバージョン指定
#include <dinput.h>

#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")


#include "WinApp.h"
//using namespace Microsoft::WRL;

class Input
{
public://メンバ関数
	//初期化
	void Initialize(WinApp*winApp);
	//更新
	void Update();

	
	bool PushKey(BYTE keyNumber);

	bool TriggerKey(BYTE keyNumber);

	//template <class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

private:
	WinApp* winApp_ = nullptr;

	// キーボードデバイスの生成
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;

	BYTE key[256] = {};

	BYTE keyPre[256] = {};
	

};

