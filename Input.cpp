#include "Input.h"
#include <cassert>

//#include <wrl.h>

//#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
//#include <dinput.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

using namespace Microsoft::WRL;

void Input::Initialize(WinApp* winApp)
{
    // 借りてきたWinAppのインスタンスを記録
    this->winApp = winApp;

    HRESULT result;

    // DirectInputの初期化
    result = DirectInput8Create(
        winApp->GetHInstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
    assert(SUCCEEDED(result));

    // キーボードデバイスの生成
    //ComPtr<IDirectInputDevice8> keyboard;
    result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
    // 入力データ形式のセット
    result = keyboard->SetDataFormat(&c_dfDIKeyboard); // 標準形式
    assert(SUCCEEDED(result));
    // 排他制御レベルのセット
    result = keyboard->SetCooperativeLevel(
        winApp->GetHwnd(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
    assert(SUCCEEDED(result));
}

void Input::Update()
{
    memcpy(keyPre, key, sizeof(key));

    // キーボード情報の取得開始
    keyboard->Acquire();

    // 全キーの入力状態を取得する
    keyboard->GetDeviceState(sizeof(key), key);
}

bool Input::PushKey(BYTE keyNumber)
{
    if (key[keyNumber]) {
        return true;
    }
    return false;
}

bool Input::TriggerKey(BYTE keyNumber)
{
    if (keyPre[keyNumber] == 0) {
        if (key[keyNumber]) {
            return true;
        }
    }
    return false;
}
