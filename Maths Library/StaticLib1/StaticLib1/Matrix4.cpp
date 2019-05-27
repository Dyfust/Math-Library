#include "Matrix4.h"
#include <cmath>

Matrix4::Matrix4(const float a_m00 /*= 1.0f*/, const float a_m01 /*= 0.0f*/, const float a_m02 /*= 0.0f*/, const float a_m03 /*= 0.0f*/,	 // Column1
	const float a_m10 /*= 0.0f*/, const float a_m11 /*= 1.0f*/, const float a_m12 /*= 0.0f*/, const float a_m13 /*= 0.0f*/,	 // Column2
	const float a_m20 /*= 0.0f*/, const float a_m21 /*= 0.0f*/, const float a_m22 /*= 1.0f*/, const float a_m23 /*= 0.0f*/,	 // Column3
	const float a_m30 /*= 0.0f*/, const float a_m31 /*= 0.0f*/, const float a_m32 /*= 0.0f*/, const float a_m33 /*= 1.0f*/) :	 // Column4
	_1D{ a_m00, a_m01, a_m02, a_m03, a_m10, a_m11, a_m12, a_m13, a_m20, a_m21, a_m22, a_m23, a_m30, a_m31, a_m32, a_m33 }
{}

Matrix4::Matrix4(const Vector4& a_right, const Vector4& a_up, const Vector4& a_forwards, const Vector4& a_position) :
	axes{ a_right , a_up , a_forwards, a_position }
{}

Matrix4::Matrix4(const Matrix4 & a_matrix)
{
	*this = a_matrix;
}

Matrix4::~Matrix4()
{

}

Matrix4::operator float*()
{
	return _1D;
}

Matrix4::operator const float*() const
{
	return _1D;
}

Vector4 & Matrix4::operator[](const int a_index)
{
	return axes[a_index];
}

const Vector4 & Matrix4::operator[](const int a_index) const
{
	return axes[a_index];
}

Matrix4 Matrix4::operator*(const Matrix4& a_rhs) const
{
	return
	{
		_2D[0][0] * a_rhs._2D[0][0] + _2D[1][0] * a_rhs._2D[0][1] + _2D[2][0] * a_rhs._2D[0][2] + _2D[3][0] * a_rhs._2D[0][3],
		_2D[0][1] * a_rhs._2D[0][0] + _2D[1][1] * a_rhs._2D[0][1] + _2D[2][1] * a_rhs._2D[0][2] + _2D[3][1] * a_rhs._2D[0][3],
		_2D[0][2] * a_rhs._2D[0][0] + _2D[1][2] * a_rhs._2D[0][1] + _2D[2][2] * a_rhs._2D[0][2] + _2D[3][2] * a_rhs._2D[0][3],
		_2D[0][3] * a_rhs._2D[0][0] + _2D[1][3] * a_rhs._2D[0][1] + _2D[2][3] * a_rhs._2D[0][2] + _2D[3][3] * a_rhs._2D[0][3],

		_2D[0][0] * a_rhs._2D[1][0] + _2D[1][0] * a_rhs._2D[1][1] + _2D[2][0] * a_rhs._2D[1][2] + _2D[3][0] * a_rhs._2D[1][3],
		_2D[0][1] * a_rhs._2D[1][0] + _2D[1][1] * a_rhs._2D[1][1] + _2D[2][1] * a_rhs._2D[1][2] + _2D[3][1] * a_rhs._2D[1][3],
		_2D[0][2] * a_rhs._2D[1][0] + _2D[1][2] * a_rhs._2D[1][1] + _2D[2][2] * a_rhs._2D[1][2] + _2D[3][2] * a_rhs._2D[1][3],
		_2D[0][3] * a_rhs._2D[1][0] + _2D[1][3] * a_rhs._2D[1][1] + _2D[2][3] * a_rhs._2D[1][2] + _2D[3][3] * a_rhs._2D[1][3],

		_2D[0][0] * a_rhs._2D[2][0] + _2D[1][0] * a_rhs._2D[2][1] + _2D[2][0] * a_rhs._2D[2][2] + _2D[3][0] * a_rhs._2D[2][3],
		_2D[0][1] * a_rhs._2D[2][0] + _2D[1][1] * a_rhs._2D[2][1] + _2D[2][1] * a_rhs._2D[2][2] + _2D[3][1] * a_rhs._2D[2][3],
		_2D[0][2] * a_rhs._2D[2][0] + _2D[1][2] * a_rhs._2D[2][1] + _2D[2][2] * a_rhs._2D[2][2] + _2D[3][2] * a_rhs._2D[2][3],
		_2D[0][3] * a_rhs._2D[2][0] + _2D[1][3] * a_rhs._2D[2][1] + _2D[2][3] * a_rhs._2D[2][2] + _2D[3][3] * a_rhs._2D[2][3],

		_2D[0][0] * a_rhs._2D[3][0] + _2D[1][0] * a_rhs._2D[3][1] + _2D[2][0] * a_rhs._2D[3][2] + _2D[3][0] * a_rhs._2D[3][3],
		_2D[0][1] * a_rhs._2D[3][0] + _2D[1][1] * a_rhs._2D[3][1] + _2D[2][1] * a_rhs._2D[3][2] + _2D[3][1] * a_rhs._2D[3][3],
		_2D[0][2] * a_rhs._2D[3][0] + _2D[1][2] * a_rhs._2D[3][1] + _2D[2][2] * a_rhs._2D[3][2] + _2D[3][2] * a_rhs._2D[3][3],
		_2D[0][3] * a_rhs._2D[3][0] + _2D[1][3] * a_rhs._2D[3][1] + _2D[2][3] * a_rhs._2D[3][2] + _2D[3][3] * a_rhs._2D[3][3]
	};
}

Vector4 Matrix4::operator*(const Vector4 & a_rhs) const
{
	return
	{
		_2D[0][0] * a_rhs.x + _2D[1][0] * a_rhs.y + _2D[2][0] * a_rhs.z + _2D[3][0] * a_rhs.w,
		_2D[0][1] * a_rhs.x + _2D[1][1] * a_rhs.y + _2D[2][1] * a_rhs.z + _2D[3][1] * a_rhs.w,
		_2D[0][2] * a_rhs.x + _2D[1][2] * a_rhs.y + _2D[2][2] * a_rhs.z + _2D[3][2] * a_rhs.w,
		_2D[0][3] * a_rhs.x + _2D[1][3] * a_rhs.y + _2D[2][3] * a_rhs.z + _2D[3][3] * a_rhs.w,
	};
}

Matrix4& Matrix4::operator*=(const Matrix4 & a_rhs)
{
	*this = *this * a_rhs;

	return *this;
}

Matrix4 Matrix4::operator+(const Matrix4 & a_rhs) const
{
	return
	{
		_2D[0][0] + a_rhs._2D[0][0], _2D[0][1] + a_rhs._2D[0][1], _2D[0][2] + a_rhs._2D[0][2], _2D[0][3] + a_rhs._2D[0][3],
		_2D[1][0] + a_rhs._2D[1][0], _2D[1][1] + a_rhs._2D[1][1], _2D[1][2] + a_rhs._2D[1][2], _2D[1][3] + a_rhs._2D[1][3],
		_2D[2][0] + a_rhs._2D[2][0], _2D[2][1] + a_rhs._2D[2][1], _2D[2][2] + a_rhs._2D[2][2], _2D[2][3] + a_rhs._2D[2][3],
		_2D[3][0] + a_rhs._2D[3][0], _2D[3][1] + a_rhs._2D[3][1], _2D[3][2] + a_rhs._2D[3][2], _2D[3][3] + a_rhs._2D[3][3]
	};
}

Matrix4 & Matrix4::operator+=(const Matrix4 & a_rhs)
{
	*this = *this + a_rhs;

	return *this;
}

Matrix4 Matrix4::operator-(const Matrix4 & a_rhs) const
{
	return
	{
		_2D[0][0] - a_rhs._2D[0][0], _2D[0][1] - a_rhs._2D[0][1], _2D[0][2] - a_rhs._2D[0][2], _2D[0][3] - a_rhs._2D[0][3],
		_2D[1][0] - a_rhs._2D[1][0], _2D[1][1] - a_rhs._2D[1][1], _2D[1][2] - a_rhs._2D[1][2], _2D[1][3] - a_rhs._2D[1][3],
		_2D[2][0] - a_rhs._2D[2][0], _2D[2][1] - a_rhs._2D[2][1], _2D[2][2] - a_rhs._2D[2][2], _2D[2][3] - a_rhs._2D[2][3],
		_2D[3][0] - a_rhs._2D[3][0], _2D[3][1] - a_rhs._2D[3][1], _2D[3][2] - a_rhs._2D[3][2], _2D[3][3] - a_rhs._2D[3][3]
	};
}

Matrix4 & Matrix4::operator-=(const Matrix4 & a_rhs)
{
	*this = *this - a_rhs;

	return *this;
}

Matrix4 & Matrix4::operator=(const Matrix4 & a_rhs)
{
	//_2D[0][0] = a_rhs._2D[0][0];
	//_2D[0][1] = a_rhs._2D[0][1];
	//_2D[0][2] = a_rhs._2D[0][2];
	//_2D[0][3] = a_rhs._2D[0][3];

	//_2D[1][0] = a_rhs._2D[1][0];
	//_2D[1][1] = a_rhs._2D[1][1];
	//_2D[1][2] = a_rhs._2D[1][2];
	//_2D[1][3] = a_rhs._2D[1][3];

	//_2D[2][0] = a_rhs._2D[2][0];
	//_2D[2][1] = a_rhs._2D[2][1];
	//_2D[2][2] = a_rhs._2D[2][2];
	//_2D[2][3] = a_rhs._2D[2][3];

	//_2D[3][0] = a_rhs._2D[3][0];
	//_2D[3][1] = a_rhs._2D[3][1];
	//_2D[3][2] = a_rhs._2D[3][2];
	//_2D[3][3] = a_rhs._2D[3][3];

	axes[0] = a_rhs.axes[0];
	axes[1] = a_rhs.axes[1];
	axes[2] = a_rhs.axes[2];
	axes[3] = a_rhs.axes[3];

	return *this;
}

void Matrix4::setRotateX(const float & a_rotation)
{
	_2D[1][1] = cos(a_rotation);
	_2D[1][2] = sin(a_rotation);
	_2D[2][1] = -sin(a_rotation);
	_2D[2][2] = cos(a_rotation);
}

void Matrix4::setRotateY(const float & a_rotation)
{
	_2D[0][0] = cos(a_rotation);
	_2D[0][2] = -sin(a_rotation);
	_2D[2][0] = sin(a_rotation);
	_2D[2][2] = cos(a_rotation);
}

void Matrix4::setRotateZ(const float & a_rotation)
{
	_2D[0][0] = cos(a_rotation);
	_2D[0][1] = sin(a_rotation);
	_2D[1][0] = -sin(a_rotation);
	_2D[1][1] = cos(a_rotation);
}