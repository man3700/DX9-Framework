#include "DXUT.h"
#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	for (auto iter : mScenes)
	{
		SAFE_RELEASE(iter.second);
		SAFE_DELETE(iter.second);
	}
	mScenes.clear();
}

void SceneManager::Update()
{
	if (mNext)
	{
		if (mCurrent) mCurrent->Release();
		mCurrent = mNext;
		mNext = nullptr;
		mCurrent->Init();
	}
	if (mCurrent)
	{
		mCurrent->Update();
	}
}

void SceneManager::Render()
{
	if (mCurrent)
		mCurrent->Render();
}

void SceneManager::Load(const string _key)
{
	mNext = mScenes[_key];
}
