#pragma once

class SoundManager : public Singleton<SoundManager>
{
public:
	SoundManager();
	~SoundManager();

	void Update();

private:
	map<string, Sound*> mSounds;
	multimap<string, SoundBuffer> mChannels;
	DXSoundManager mManager;

public:
	void Create(string _key, LPWSTR _path);
	void Play(string _key, bool _loop, int _volume);
	void Stop();
	void Stop(string _key);

};
