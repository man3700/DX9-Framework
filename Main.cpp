#include "DXUT.h"
#include "Main.h"

void Main::Init()
{
	CameraManager::InitInstance();
	InputManager::InitInstance();
	ObjectManager::InitInstance();
	SoundManager::InitInstance();
	RenderManager::InitInstance();
	SceneManager::InitInstance();
	TextureManager::InitInstance();

	SceneM->Load("InGame");
}

void Main::Update()
{
	CameraM->Update();
	InputM->Update();
	ObjectM->Update();
	SoundM->Update();
	SceneM->Update();
}

void Main::Render()
{
	RenderM->Begin();

	CameraM->Render();
	ObjectM->Render();
	SceneM->Render();

	RenderM->End();
}

void Main::Release()
{
	CameraManager::ReleaseInstance();
	InputManager::ReleaseInstance();
	ObjectManager::ReleaseInstance();
	SoundManager::ReleaseInstance();
	RenderManager::ReleaseInstance();
	SceneManager::ReleaseInstance();
	TextureManager::ReleaseInstance();
}

void Main::OnLostDevice()
{
	RenderM->OnLostDevice();
}

void Main::OnResetDevice()
{
	RenderM->OnResetDevice();
}
