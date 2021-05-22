#include "DXUT.h"
#include "InputManager.h"

InputManager::InputManager()
{
	memset(mCurrent, false, 256);
	memset(mLatest, false, 256);
}

InputManager::~InputManager()
{
}

void InputManager::Update()
{
	memcpy(mLatest, mCurrent, 256);
	for (int i = 0; i < 256; i++)
		mCurrent[i] = GetAsyncKeyState(i) & 0x8000;
}

bool InputManager::KeyPress(const int _key)
{
	return mCurrent[_key] || mLatest[_key];
}

bool InputManager::KeyDown(const int _key)
{
	return mCurrent[_key] && !mLatest[_key];
}

bool InputManager::KeyUp(const int _key)
{
	return !mCurrent[_key] && mLatest[_key];
}
