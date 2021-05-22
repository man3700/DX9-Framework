#pragma once
#include "Texture.h"

class TextureManager : public Singleton<TextureManager>
{
public:
	TextureManager();
	virtual ~TextureManager();

private:
	map<string, vector<Texture*>> mTextures;
	
public:
	void Create(string _key, string _path, int _layer = 1);
	Texture* Load(string _key, int _layer = 1);

};
