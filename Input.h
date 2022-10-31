#pragma once
#include <windows.h>
#include <wrl.h>

#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
#include <dinput.h>

#include "WinApp.h"

class Input {
public:
	template <class T>using ComPtr = Microsoft::WRL::ComPtr<T>;
public:
	void Initialize(WinApp* winApp);

	void Update();

	bool PushKey(BYTE keyNumber);

	bool TriggerKey(BYTE keyNumber);

private:
	ComPtr<IDirectInputDevice8> keyboard;
	ComPtr<IDirectInput8> directInput;

	BYTE key[256] = {};
	BYTE keyPre[256] = {};

	// WindowsAPI
	WinApp* winApp = nullptr;
};