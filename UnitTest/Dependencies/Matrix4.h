#pragma once
#ifndef MATRIX4_H
#define MATRIX4_H
#include "Vector4.h"

class Matrix4
{
public:

	// Different ways of identifying the same data.
	union
	{
		struct
		{
			float x_axis[4];
			float y_axis[4];
			float z_axis[4];
			float w_axis[4];
		};
		struct
		{
			Vector4 right;
			Vector4 up;
			Vector4 forwards;
			Vector4 position;
		};
		float _1D[16];
		float _2D[4][4];
		Vector4 axes[4];
	};


	// Initializer list.
	Matrix4(const float m00 = 1.0f, const float m01 = 0.0f, const float m02 = 0.0f, const float m03 = 0.0f,	 // Column1
		const float m10 = 0.0f, const float m11 = 1.0f, const float m12 = 0.0f, const float m13 = 0.0f,	 // Column2
		const float m20 = 0.0f, const float m21 = 0.0f, const float m22 = 1.0f, const float m23 = 0.0f,
		const float m30 = 0.0f, const float m31 = 0.0f, const float m32 = 0.0f, const float m33 = 1.0f);

	Matrix4(const Vector4& right, const Vector4& up, const Vector4& forwards, const Vector4& position);
	Matrix4(const Matrix4& matrix);
	~Matrix4();

	// Overloaded subscript operator to access the different axes in the matrix.
	Vector4& operator[] (const int index);
	const Vector4& operator[] (const int index) const;

	// Overloaded float* operator to get a pointer to an array of elements which forms an axis. (tbh, im not really sure what this does to be exact)
	operator float* ();
	operator const float* () const;

	// Overloaded arithmetic operations with matrices & vectors.
	Matrix4 operator* (const Matrix4& rhs) const;
	Vector4 operator* (const Vector4& rhs) const;
	Matrix4& operator*= (const Matrix4& rhs);
	Matrix4 operator+ (const Matrix4& rhs) const;
	Matrix4& operator+= (const Matrix4& rhs);
	Matrix4 operator- (const Matrix4& rhs) const;
	Matrix4& operator-= (const Matrix4& rhs);

	// Overloaded assignment operator.
	Matrix4& operator= (const Matrix4& rhs);

	// Functions to transform the matrix into a rotation matrix.
	void setRotateX(const float& rotation);
	void setRotateY(const float& rotation);
	void setRotateZ(const float& rotation);
};
#endif // !MATRIX4_H