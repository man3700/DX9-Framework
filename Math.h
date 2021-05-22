#pragma once

namespace math
{
	template<typename T> T Lerp(T _begin, T _end, float _time)
	{
		return _begin + (_end - _begin) * _time;
	}

	float Random(float _min, float _max);

	int Random(int _min, int _max);

	D3DXVECTOR2 Rotate(D3DXVECTOR2 _vector, float _rot);

	float Toward(D3DXVECTOR2 _vector1, D3DXVECTOR2 _vector2);

	float Clamp(float _value, float _min, float _max);
};
