#pragma once

#include <windows.h>

#define DIRECTINPUT_VERSION  0x0800//DirectInput�̃o�[�W�����w��
#include <dinput.h>

#include <wrl.h>

class Input
{
public://�����o�֐�
	//������
	void Initialize(HINSTANCE hinstance,HWND hwnd);
	//�X�V
	void Update();

	
	bool PushKey(BYTE keyNumber);

	bool TriggerKey(BYTE keyNumber);

	template <class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

private:
	// �L�[�{�[�h�f�o�C�X�̐���
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;

	BYTE key[256] = {};

	BYTE keyPre[256] = {};

};

