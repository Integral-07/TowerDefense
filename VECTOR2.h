#pragma once

#include <math.h>

struct VECTOR2 {

	float x = 0;
	float y = 0;

	VECTOR2();
	VECTOR2(float, float);

	static VECTOR2 normalize(VECTOR2&);

	VECTOR2 operator*(float) const;
	VECTOR2 operator+=(VECTOR2);
	friend VECTOR2 operator+(VECTOR2, VECTOR2);
	friend VECTOR2 operator-(VECTOR2, VECTOR2);

	void set(float, float);
};

inline VECTOR2::VECTOR2()
{
}

inline VECTOR2::VECTOR2(float _x, float _y) {

	x = _x;
	y = _y;
}

inline VECTOR2 VECTOR2::normalize(VECTOR2& vec)
{
	float root_len = vec.x * vec.x + vec.y * vec.y;
	return VECTOR2(vec.x / sqrt(root_len), vec.y / sqrt(root_len));
}

inline VECTOR2 VECTOR2::operator*(float k) const
{
	return VECTOR2(this->x * k, this->y * k);
}

inline VECTOR2 VECTOR2::operator+=(VECTOR2 vec)
{
	return vec + (*this);
}

inline void VECTOR2::set(float _x, float _y)
{
	this->x = _x;
	this->y = _y;
}
