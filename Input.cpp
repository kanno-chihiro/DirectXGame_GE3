#include "Input.h"
#include <cassert>

#pragma comment(lib,"dinput8,lib")
#pragma comment(lid,"dxguid,lib")

#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <dinput.h>

#include <wrl.h>

using namespace Microsoft::WRL;

void Input::Initialize(HINSTANCE hInstance, HWND hwnd)
{
    HRESULT result;
    // DirectInput�̏�����
    ComPtr<IDirectInput8> directInput;
    result = DirectInput8Create(
        hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
    assert(SUCCEEDED(result));

    // �L�[�{�[�h�f�o�C�X�̐���
    ComPtr<IDirectInputDevice8> keyboard;
    result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
    // ���̓f�[�^�`���̃Z�b�g
    result = keyboard->SetDataFormat(&c_dfDIKeyboard); // �W���`��
    assert(SUCCEEDED(result));
    // �r�����䃌�x���̃Z�b�g
    result = keyboard->SetCooperativeLevel(
        hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
    assert(SUCCEEDED(result));
}

void Input::Update()
{

    BYTE key[256] = {};

    // �L�[�{�[�h���̎擾�J�n
    keyboard->Acquire();
    // �S�L�[�̓��͏�Ԃ��擾����
    keyboard->GetDeviceState(sizeof(key), key);
}