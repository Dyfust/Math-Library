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

	// Different ways of identifying the same data.
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

	// Overloaded subscript operator to access the different elements in the vector.
	float& operator[] (const int index);

	// Overloaded float* operator to get a pointer to the array of elements contained in the vector. (tbh, im not really sure what this does to be exact)
	operator float* ();
	operator const float* () const;

	// Overloaded arithmetic operations with scalars & vectors. (You never multiple/divide a vector by another vector so they're excluded)
	Vector3 operator+ (const Vector3& rhs) const;
	Vector3 operator- (const Vector3& rhs) const;
	Vector3 operator* (const float scalar) const;
	Vector3 operator/ (const float scalar) const;
	Vector3& operator+= (const Vector3 rhs);
	Vector3& operator-= (const Vector3& rhs);
	Vector3& operator*= (const float scalar);
	Vector3& operator/= (const float scalar);

	// Overloaded assignment operator.
	Vector3& operator= (const Vector3& rhs);

	// Returns the square rooted magnitude of the vector.
	float square_magnitude() const;

	// Returns the squared magnitude of the vector.
	float magnitude() const;

	// Returns a normalized instance of this vector.
	void normalise();

	// Normalizes the vector.
	Vector3 normalized() const;

	// Returns the dot product of this and rhs.
	float dot(Vector3& rhs) const;

	// Returns the cross product between the two vectors. (A vector that is perpendicular to the two)
	Vector3 cross(Vector3& rhs) const;
};

// Overloaded multiplication operator where the lhs is a float.
Vector3 operator* (const float lhs, const Vector3 rhs);
#endif // !VECTOR3_H