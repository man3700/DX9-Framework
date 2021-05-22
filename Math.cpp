#include "DXUT.h"
#include "Math.h"

float math::Random(float _min, float _max)
{
	return _min + (rand() | (rand() << 16)) % (int)(_max * 10000 - _min * 10000 + 1) * 0.0001;
}

int math::Random(int _min, int _max)
{
	return Random(_min * 10000.f, _max * 10000.f) * 0.0001;
}

D3DXVECTOR2 math::Rotate(D3DXVECTOR2 _vector, float _rot)
{
	float rot = D3DXToRadian(_rot);
	return { _vector.x * cosf(rot) + _vector.y * -sinf(rot), _vector.x * sinf(rot) + _vector.y * cosf(rot) };
}

float math::Toward(Vector2 _vector1, Vector2 _vector2)
{
	return D3DXToDegree(atan2(_vector2.y - _vector1.y, _vector2.x - _vector1.x));
}

float math::Clamp(float _value, float _min, float _max)
{
	return min(max(_value, _min), _max);
}
