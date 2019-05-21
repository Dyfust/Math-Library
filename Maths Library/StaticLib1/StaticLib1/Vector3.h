#pragma once
#ifndef VECTOR3_H
#define VECTOR3_H

#include <cassert>
#include <cmath>

class Vector3
{
public:
	Vector3();
	Vector3(float x, float y, float z);

	union
	{
		struct
		{
			float x;
			float y;
			float z;
		};
		struct
		{
			float r;
			float g;
			float b;
		};
		struct
		{
			float i;
			float j;
			float k;
		};
		float data[3];
	};

	float& operator[] (const int index);

	operator float* ();

	operator const float* () const;

	Vector3 operator+ (Vector3& rhs) const;
	Vector3 operator- (Vector3& rhs) const;
	Vector3 operator* (float scalar) const;
	Vector3 operator/ (float scalar) const;

	Vector3& operator+= (Vector3 rhs);
	Vector3& operator-= (Vector3& rhs);
	Vector3& operator*= (float scalar);
	Vector3& operator/= (float scalar);

	Vector3& operator= (Vector3& rhs);

	float square_magnitude() const;
	float magnitude() const;

	void normalize();
	Vector3 normalized() const;

	float dot(Vector3& rhs) const;
	Vector3 cross(Vector3& rhs) const;
};

#endif // !VECTOR3_H