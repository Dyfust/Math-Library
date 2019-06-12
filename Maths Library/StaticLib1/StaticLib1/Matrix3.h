#pragma once
#include "Vector3.h"

class Matrix3								
{
public:
	~Matrix3();

	// Different ways of identifying the same data.
	union
	{
		struct
		{
			float x_axis[3];
			float y_axis[3];
			float translation[3];
		};
		struct
		{
			Vector3 right;
			Vector3 forward;
			Vector3 position;
		};

		float _1D[9];
		float _2D[3][3];
		Vector3 axes[3];
	};

	// Intializer list.
	Matrix3(float one = 1.0f, float two = 0.0f, float three = 0.0f, float four = 0.0f, float five = 1.0f, float six = 0.0f, float seven = 0.0f, float eight = 0.0f, float nine = 1.0f);
	Matrix3(Vector3 right, Vector3 forward, Vector3 position);
	Matrix3(float* x_axis, float* y_axis, float* translation);

	// Overloaded subscript operator to access the different axes in the matrix.
	Vector3& operator[] (const int index);

	// Overloaded float* operator to get a pointer to an array of elements which forms an axis. (tbh, im not really sure what this does to be exact)
	operator float*();
	operator const float*() const;

	// Overloaded arithmetic operations with matrices & vectors.
	Matrix3 operator+ (const Matrix3& rhs) const;
	Matrix3 operator- (const Matrix3& rhs) const;
	Matrix3 operator* (const Matrix3& rhs) const;
	Matrix3& operator+= (const Matrix3& rhs);
	Matrix3& operator-= (const Matrix3& rhs);
	Matrix3& operator*= (const Matrix3& rhs);
	Vector3 operator* (const Vector3& rhs) const;

	// Overloaded assignment operator.
	Matrix3& operator= (const Matrix3& rhs);

	// Functions to transform the matrix into a rotation matrix.
	void setRotateX(const float& rotation);
	void setRotateY(const float& rotation);
	void setRotateZ(const float& rotation);
};