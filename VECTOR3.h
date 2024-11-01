#pragma once

#include <math.h>

struct VECTOR3 {

	float x = 0;
	float y = 0;
	float z = 0;

	VECTOR3();
	VECTOR3(float, float, float);

	void set(float, float, float);
};

inline VECTOR3::VECTOR3()
{
}

inline VECTOR3::VECTOR3(float _x, float _y, float _z) {

	x = _x;
	y = _y;
	z = _z;
}

inline void VECTOR3::set(float _x, float _y, float _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}
