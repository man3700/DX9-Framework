#pragma once

class Main
{
public:
	Main() {}
	~Main() {}

	void Init();
	void Update();
	void Render();
	void Release();

	void OnLostDevice();
	void OnResetDevice();
};
