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
	~Vector3();

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

	Vector3 operator+ (const Vector3& rhs) const;
	Vector3 operator- (const Vector3& rhs) const;
	Vector3 operator* (const float scalar) const;
	Vector3 operator/ (const float scalar) const;

	Vector3& operator+= (const Vector3 rhs);
	Vector3& operator-= (const Vector3& rhs);
	Vector3& operator*= (const float scalar);
	Vector3& operator/= (const float scalar);

	Vector3& operator= (const Vector3& rhs);

	float square_magnitude() const;
	float magnitude() const;

	void normalise();
	Vector3 normalized() const;

	float dot(Vector3& rhs) const;
	Vector3 cross(Vector3& rhs) const;
};

Vector3 operator* (const float lhs, const Vector3 rhs);

#endif // !VECTOR3_H