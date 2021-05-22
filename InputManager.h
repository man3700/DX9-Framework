#pragma once

class InputManager : public Singleton<InputManager>
{
public:
	InputManager();
	virtual ~InputManager();

	void Update();

private:
	bool mCurrent[256];
	bool mLatest[256];

public:
	bool KeyPress(int _key);
	bool KeyDown(int _key);
	bool KeyUp(int _key);

};

