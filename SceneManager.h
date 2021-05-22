#pragma once
#include "Scene.h"

class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager();
	virtual ~SceneManager();

	void Update();
	void Render();

private:
	Scene* mCurrent = nullptr;
	Scene* mNext = nullptr;
	map<string, Scene*> mScenes;

public:
	void Load(string _key);

};

