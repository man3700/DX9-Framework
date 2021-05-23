#pragma once

class Texture;

class RenderManager : public Singleton<RenderManager>
{
public:
	RenderManager();
	virtual ~RenderManager();

	void OnLostDevice();
	void OnResetDevice();

private:
	Matrix mMatrix, mScaleMat, mRotMat, mTransMat;
	Sprite mSprite;

public:
	void Begin();
	void End();

	void Render(Texture* _texture, Vector2 _pos, Vector2 _scale, Vector2 _pivot, Color _color, Rect _rect , float _rot, float _depth, float _isView);
};
