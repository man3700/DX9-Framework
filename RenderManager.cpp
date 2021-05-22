#include "DXUT.h"
#include "RenderManager.h"

RenderManager::RenderManager()
{
	D3DXCreateSprite(Device, &mSprite);

	for (int i = 0; i < 32; i++)
	{
		D3DXCreateFont(Device, i + 1, 0, 0, 1, false, DEFAULT_CHARSET, 0, 0, 0, L"System", &mEng[i]);
		D3DXCreateFont(Device, i + 1, 0, 0, 1, false, DEFAULT_CHARSET, 0, 0, 0, L"ÈÞ¸ÕµÕ±ÙÇìµå¶óÀÎ", &mKor[i]);
	}
}

RenderManager::~RenderManager()
{
	mSprite->Release();

	for (int i = 0; i < 32; i++)
	{
		mKor[i]->Release();
		mEng[i]->Release();
	}
}

void RenderManager::OnLostDevice()
{
	mSprite->OnLostDevice();
}

void RenderManager::OnResetDevice()
{
	mSprite->OnResetDevice();
}

void RenderManager::Begin()
{
	mSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_DEPTH_FRONTTOBACK);
	Device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DX_FILTER_NONE);
	Device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DX_FILTER_NONE);
	Device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DX_FILTER_NONE);
}

void RenderManager::End()
{
	mSprite->End();
}

void RenderManager::Render(Texture* _texture, Vector2 _pos, Vector2 _scale, Vector2 _pivot, Color _color, Rect _rect, float _rot, float _depth, float _isView)
{
	if (_texture)
	{
		D3DXMatrixScaling(&mScaleMat, _scale.x, _scale.y, 1.f);
		D3DXMatrixRotationZ(&mRotMat, D3DXToRadian(_rot));
		D3DXMatrixTranslation(&mTransMat, _pos.x, _pos.y, 0.f);

		mMatrix = mScaleMat * mRotMat * mTransMat;
		mMatrix._43 = 1.f - _depth * 0.0001f;

		Rect rect = (_rect.left == -1) ? Rect{ 0, 0, (long)_texture->mInfo.Width, (long)_texture->mInfo.Height } : _rect;

		Vector3 pivot = { _texture->mInfo.Width * _pivot.x, _texture->mInfo.Height * _pivot.y, 0.f };

		if (_isView) mMatrix *= CameraM->GetMatrix();

		mSprite->SetTransform(&mMatrix);
		mSprite->Draw(_texture->mImage, &rect, &pivot, nullptr, _color);
	}
}
