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

	template <class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

private:
	ComPtr<IDirectInput8> directInput;

	// �L�[�{�[�h�f�o�C�X�̐���
	ComPtr<IDirectInputDevice8> keyboard;

};

