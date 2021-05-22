#include "DXUT.h"
#include "SoundManager.h"

SoundManager::SoundManager()
{
	mManager.Initialize(DXUTGetHWND(), 2);
}

SoundManager::~SoundManager()
{
	for (auto& iter : mChannels)
	{
		iter.second->Release();
	}
	for (auto& iter : mSounds)
	{
		delete iter.second;
		iter.second = nullptr;
	}
}

void SoundManager::Update()
{
	DWORD status;

	for (auto& iter = mChannels.begin(); iter != mChannels.end();)
	{
		(*iter).second->GetStatus(&status);

		if (!(status & DSBSTATUS_PLAYING))
		{
			(*iter).second->Release();
			iter = mChannels.erase(iter);
		}
		else iter++;
	}
}

void SoundManager::Create(string _key, LPWSTR _path)
{
	CSound** sound = new CSound * ();
	mManager.Create(sound, _path, DSBCAPS_CTRLVOLUME);
	mSounds[_key] = *sound;
	delete sound;
}

void SoundManager::Play(string _key, bool _loop, int _volume)
{
	LPDIRECTSOUNDBUFFER buffer;
	mManager.GetDirectSound()->DuplicateSoundBuffer(mSounds[_key]->GetBuffer(0), &buffer);
	buffer->Play(0, 0, _loop ? DSBPLAY_LOOPING : 0);
	buffer->SetVolume(-5000 + _volume * 500);
	mChannels.insert(make_pair(_key, buffer));
}

void SoundManager::Stop()
{
	for (auto& iter : mChannels)
		iter.second->Release();
	mChannels.clear();
}

void SoundManager::Stop(string _key)
{
	for (auto& iter = mChannels.begin(); iter != mChannels.end();)
	{
		if ((*iter).first == _key)
		{
			(*iter).second->Release();
			iter = mChannels.erase(iter);
		}
		else iter++;
	}
}
