#include "DXUT.h"
#include "CameraManager.h"

CameraManager::CameraManager()
{
	D3DXMatrixOrthoLH(&mProj, WinSize.x, -WinSize.y, 0, 1);
}

CameraManager::~CameraManager()
{
}

void CameraManager::Update()
{
	if (mShakeDuration < mShakeLimit)
	{
		mShake = { Random(0.f, mForce), Random(0.f, mForce) };
		mShakeDuration += DeltaTime;
	}
	else
	{
		mShake = Vec2Zero;
	}

	D3DXMatrixTranslation(&mTransMat, mPos.x + mShake.x, - mPos.y + mShake.y, 0.f);
	D3DXMatrixScaling(&mScaleMat, mScale, mScale, 1.f);
	D3DXMatrixRotationZ(&mRotMat, D3DXToRadian(- mAngle));
	
	mView = mTransMat * mScaleMat * mRotMat;
}

void CameraManager::Render()
{
	Device->SetTransform(D3DTS_VIEW, &mView);
	Device->SetTransform(D3DTS_PROJECTION, &mProj);
}

Matrix CameraManager::GetMatrix()
{
	Matrix matrix;
	D3DXMatrixInverse(&matrix, nullptr, &mView);
	return matrix;
}
