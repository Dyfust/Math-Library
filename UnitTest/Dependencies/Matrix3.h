#pragma once
#include "Vector3.h"

class Matrix3								
{
public:
	~Matrix3();

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

	Matrix3(float one = 1.0f, float two = 0.0f, float three = 0.0f, float four = 0.0f, float five = 1.0f, float six = 0.0f, float seven = 0.0f, float eight = 0.0f, float nine = 1.0f);
	Matrix3(Vector3 right, Vector3 forward, Vector3 position);
	Matrix3(float* x_axis, float* y_axis, float* translation);

	operator float*();
	operator const float*() const;
	Vector3& operator[] (const int index_a);

	Matrix3 operator+ (Matrix3& rhs);
	Matrix3 operator- (Matrix3& rhs);
	Matrix3 operator* (Matrix3& rhs);
	Matrix3& operator+= (Matrix3& rhs);
	Matrix3& operator-= (Matrix3& rhs);
	Matrix3& operator*= (Matrix3& rhs);

	Vector3 operator* (Vector3& rhs);

	void setRotateX(const float& a_rotation);
	void setRotateY(const float& a_rotation);
	void setRotateZ(const float& a_rotation);
};