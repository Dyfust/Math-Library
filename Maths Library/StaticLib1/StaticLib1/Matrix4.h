#pragma once
#ifndef MATRIX4_H
#define MATRIX4_H
#include "Vector4.h"

class Matrix4
{
public:

	// --- Data definitions ---
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


	// --- Constructors ---
	Matrix4(const float a_m00 = 1.0f, const float a_m01 = 0.0f, const float a_m02 = 0.0f, const float a_m03 = 0.0f,	 // Column1
		const float a_m10 = 0.0f, const float a_m11 = 1.0f, const float a_m12 = 0.0f, const float a_m13 = 0.0f,	 // Column2
		const float a_m20 = 0.0f, const float a_m21 = 0.0f, const float a_m22 = 1.0f, const float a_m23 = 0.0f,
		const float a_m30 = 0.0f, const float a_m31 = 0.0f, const float a_m32 = 0.0f, const float a_m33 = 1.0f);

	Matrix4(const Vector4& a_right, const Vector4& a_up, const Vector4& a_forwards, const Vector4& a_position);

	Matrix4(const Matrix4& a_matrix);

	~Matrix4();


	//! \brief Casting mutable float* operator overloading.
	operator float* ();
	//! \brief Casting read only float* operator overloading.
	operator const float* () const;

	// --- Operator overloads ---
	Vector4& operator [] (const int a_index);

	const Vector4& operator [] (const int a_index) const;

	Matrix4 operator* (const Matrix4& a_rhs) const;

	Vector4 operator* (const Vector4& a_rhs) const;

	Matrix4& operator*= (const Matrix4& a_rhs);

	Matrix4 operator+ (const Matrix4& a_rhs) const;

	Matrix4& operator+= (const Matrix4& a_rhs);

	Matrix4 operator- (const Matrix4& a_rhs) const;

	Matrix4& operator-= (const Matrix4& a_rhs);

	Matrix4& operator= (const Matrix4& a_rhs);

	// --- Transform controls ---

	void setRotateX(const float& a_rotation);
	void setRotateY(const float& a_rotation);
	void setRotateZ(const float& a_rotation);
};
#endif // !MATRIX4_H