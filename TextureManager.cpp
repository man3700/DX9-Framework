#include "DXUT.h"
#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	for (auto iter : mTextures)
	{
		for (auto texture : iter.second)
		{
			texture->mImage->Release();
			delete texture;
			texture = nullptr;
		}
	}

	mTextures.clear();
}

void TextureManager::Create(string _key, string _path, int _layer)
{
	vector<Texture*> textures;

	for (int i = 1; i <= _layer; i++)
	{
		LPDIRECT3DTEXTURE9 image;
		D3DXIMAGE_INFO info;

		char path[256];
		wsprintfA(path, _path.c_str(), i);

		if (D3DXCreateTextureFromFileExA(Device, path, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
			D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_POINT, D3DX_FILTER_POINT, 0, &info, 0, &image) == S_OK)
			textures.push_back(new Texture(image, info));
	}

	if (!textures.empty())
		mTextures[_key] = textures;
}

Texture* TextureManager::Load(string _key, int _layer)
{
	auto find = mTextures.find(_key);
	if (find != mTextures.end())
		return (*find).second[_layer - 1];
	return nullptr;
}
