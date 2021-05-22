#pragma once

class CameraManager : public Singleton<CameraManager>
{
public:
	CameraManager();
	~CameraManager();

	void Update();
	void Render();

private:
	Matrix mView, mProj;
	Matrix mScaleMat, mRotMat, mTransMat;

	//Shake
	Vector2 mShake = { 0.f, 0.f };
	float mForce = 0.f;
	float mShakeDuration = 0.f;
	float mShakeLimit = 0.f;

	//Lock
	Rect mLock = { 0, 0, 0, 0 };
	bool mIsLock = false;

public:
	Vector2 mPos = Vec2Zero;
	float mScale = 1.f;
	float mAngle = 0.f;

	Matrix GetMatrix();

};
