#include "DXUT.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	for (auto iter : mObjects)
		SAFE_DELETE(iter);
	mObjects.clear();
}

void ObjectManager::Update()
{
	for (auto iter = mObjects.begin(); iter != mObjects.end();)
	{
		if ((*iter)->mIsDestroy)
		{
			SAFE_DELETE(*iter);
			iter = mObjects.erase(iter);
		}
		else
		{
			if ((*iter)->mIsActive)
				(*iter)->Update();
			iter++;
		}
	}
}

void ObjectManager::Render()
{
	for (auto iter : mObjects)
		iter->Render();
}
