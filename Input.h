#pragma once

#include <windows.h>
#include <wrl.h>

#define DIRECTINPUT_VERSION  0x0800//DirectInput�̃o�[�W�����w��
#include <dinput.h>

#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")


#include "WinApp.h"
//using namespace Microsoft::WRL;

class Input
{
public://�����o�֐�
	//������
	void Initialize(WinApp*winApp);
	//�X�V
	void Update();

	
	bool PushKey(BYTE keyNumber);

	bool TriggerKey(BYTE keyNumber);

	//template <class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

private:
	WinApp* winApp_ = nullptr;

	// �L�[�{�[�h�f�o�C�X�̐���
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;

	BYTE key[256] = {};

	BYTE keyPre[256] = {};
	

};

