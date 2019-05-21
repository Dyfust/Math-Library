#pragma once
#include "Vector3.h"

class Matrix3								
{
public:
	Matrix3();
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

		float _2D[3][3];
	};

	Matrix3(Vector3 right, Vector3 forward, Vector3 position);
	Matrix3(float* x_axis, float* y_axis, float* translation);

	float* operator[] (const int index_a);

	Matrix3 operator+ (Matrix3& rhs);
	Matrix3 operator- (Matrix3& rhs);
	Matrix3 operator* (Matrix3& rhs);
};    