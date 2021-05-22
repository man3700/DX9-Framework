#pragma once

template <typename T> class Singleton
{
public:
	Singleton() {}
	virtual ~Singleton() {}

private:
	static T* mInstance;

public:
	static void InitInstance() { mInstance = new T; }
	static void ReleaseInstance() { SAFE_DELETE(mInstance); }
	static T* GetInstance() { return mInstance; }
};

template<typename T> T* Singleton<T>::mInstance = nullptr;