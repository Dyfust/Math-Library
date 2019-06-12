#include "Matrix4.h"
#include <cmath>

Matrix4::Matrix4(const float m00 /*= 1.0f*/, const float m01 /*= 0.0f*/, const float m02 /*= 0.0f*/, const float m03 /*= 0.0f*/, // Column1
	const float m10 /*= 0.0f*/, const float m11 /*= 1.0f*/, const float m12 /*= 0.0f*/, const float m13 /*= 0.0f*/,	 // Column2
	const float m20 /*= 0.0f*/, const float m21 /*= 0.0f*/, const float m22 /*= 1.0f*/, const float m23 /*= 0.0f*/,	 // Column3
	const float m30 /*= 0.0f*/, const float m31 /*= 0.0f*/, const float m32 /*= 0.0f*/, const float m33 /*= 1.0f*/): // Column4
	_1D{ m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33 }
{}

Matrix4::Matrix4(const Vector4& right, const Vector4& up, const Vector4& forwards, const Vector4& position) :
	axes{right, up, forwards, position}
{}

Matrix4::Matrix4(const Matrix4 & matrix)
{
	*this = matrix;
}

Matrix4::~Matrix4()
{ }

Matrix4::operator float*()
{
	return _1D;
}

Matrix4::operator const float*() const
{
	return _1D;
}

Vector4 & Matrix4::operator[](const int index)
{
	return axes[index];
}

const Vector4 & Matrix4::operator[](const int index) const
{
	return axes[index];
}

Matrix4 Matrix4::operator*(const Matrix4& rhs) const
{
	return
	{
		_2D[0][0] * rhs._2D[0][0] + _2D[1][0] * rhs._2D[0][1] + _2D[2][0] * rhs._2D[0][2] + _2D[3][0] * rhs._2D[0][3],
		_2D[0][1] * rhs._2D[0][0] + _2D[1][1] * rhs._2D[0][1] + _2D[2][1] * rhs._2D[0][2] + _2D[3][1] * rhs._2D[0][3],
		_2D[0][2] * rhs._2D[0][0] + _2D[1][2] * rhs._2D[0][1] + _2D[2][2] * rhs._2D[0][2] + _2D[3][2] * rhs._2D[0][3],
		_2D[0][3] * rhs._2D[0][0] + _2D[1][3] * rhs._2D[0][1] + _2D[2][3] * rhs._2D[0][2] + _2D[3][3] * rhs._2D[0][3],

		_2D[0][0] * rhs._2D[1][0] + _2D[1][0] * rhs._2D[1][1] + _2D[2][0] * rhs._2D[1][2] + _2D[3][0] * rhs._2D[1][3],
		_2D[0][1] * rhs._2D[1][0] + _2D[1][1] * rhs._2D[1][1] + _2D[2][1] * rhs._2D[1][2] + _2D[3][1] * rhs._2D[1][3],
		_2D[0][2] * rhs._2D[1][0] + _2D[1][2] * rhs._2D[1][1] + _2D[2][2] * rhs._2D[1][2] + _2D[3][2] * rhs._2D[1][3],
		_2D[0][3] * rhs._2D[1][0] + _2D[1][3] * rhs._2D[1][1] + _2D[2][3] * rhs._2D[1][2] + _2D[3][3] * rhs._2D[1][3],

		_2D[0][0] * rhs._2D[2][0] + _2D[1][0] * rhs._2D[2][1] + _2D[2][0] * rhs._2D[2][2] + _2D[3][0] * rhs._2D[2][3],
		_2D[0][1] * rhs._2D[2][0] + _2D[1][1] * rhs._2D[2][1] + _2D[2][1] * rhs._2D[2][2] + _2D[3][1] * rhs._2D[2][3],
		_2D[0][2] * rhs._2D[2][0] + _2D[1][2] * rhs._2D[2][1] + _2D[2][2] * rhs._2D[2][2] + _2D[3][2] * rhs._2D[2][3],
		_2D[0][3] * rhs._2D[2][0] + _2D[1][3] * rhs._2D[2][1] + _2D[2][3] * rhs._2D[2][2] + _2D[3][3] * rhs._2D[2][3],

		_2D[0][0] * rhs._2D[3][0] + _2D[1][0] * rhs._2D[3][1] + _2D[2][0] * rhs._2D[3][2] + _2D[3][0] * rhs._2D[3][3],
		_2D[0][1] * rhs._2D[3][0] + _2D[1][1] * rhs._2D[3][1] + _2D[2][1] * rhs._2D[3][2] + _2D[3][1] * rhs._2D[3][3],
		_2D[0][2] * rhs._2D[3][0] + _2D[1][2] * rhs._2D[3][1] + _2D[2][2] * rhs._2D[3][2] + _2D[3][2] * rhs._2D[3][3],
		_2D[0][3] * rhs._2D[3][0] + _2D[1][3] * rhs._2D[3][1] + _2D[2][3] * rhs._2D[3][2] + _2D[3][3] * rhs._2D[3][3]
	};
}

Vector4 Matrix4::operator*(const Vector4& rhs) const
{
	return
	{
		_2D[0][0] * rhs.x + _2D[1][0] * rhs.y + _2D[2][0] * rhs.z + _2D[3][0] * rhs.w,
		_2D[0][1] * rhs.x + _2D[1][1] * rhs.y + _2D[2][1] * rhs.z + _2D[3][1] * rhs.w,
		_2D[0][2] * rhs.x + _2D[1][2] * rhs.y + _2D[2][2] * rhs.z + _2D[3][2] * rhs.w,
		_2D[0][3] * rhs.x + _2D[1][3] * rhs.y + _2D[2][3] * rhs.z + _2D[3][3] * rhs.w,
	};
}

Matrix4& Matrix4::operator*=(const Matrix4& rhs)
{
	*this = *this * rhs;

	return *this;
}

Matrix4 Matrix4::operator+(const Matrix4& rhs) const
{
	return
	{
		_2D[0][0] + rhs._2D[0][0], _2D[0][1] + rhs._2D[0][1], _2D[0][2] + rhs._2D[0][2], _2D[0][3] + rhs._2D[0][3],
		_2D[1][0] + rhs._2D[1][0], _2D[1][1] + rhs._2D[1][1], _2D[1][2] + rhs._2D[1][2], _2D[1][3] + rhs._2D[1][3],
		_2D[2][0] + rhs._2D[2][0], _2D[2][1] + rhs._2D[2][1], _2D[2][2] + rhs._2D[2][2], _2D[2][3] + rhs._2D[2][3],
		_2D[3][0] + rhs._2D[3][0], _2D[3][1] + rhs._2D[3][1], _2D[3][2] + rhs._2D[3][2], _2D[3][3] + rhs._2D[3][3]
	};
}

Matrix4& Matrix4::operator+=(const Matrix4& rhs)
{
	*this = *this + rhs;

	return *this;
}

Matrix4 Matrix4::operator-(const Matrix4& rhs) const
{
	return
	{
		_2D[0][0] - rhs._2D[0][0], _2D[0][1] - rhs._2D[0][1], _2D[0][2] - rhs._2D[0][2], _2D[0][3] - rhs._2D[0][3],
		_2D[1][0] - rhs._2D[1][0], _2D[1][1] - rhs._2D[1][1], _2D[1][2] - rhs._2D[1][2], _2D[1][3] - rhs._2D[1][3],
		_2D[2][0] - rhs._2D[2][0], _2D[2][1] - rhs._2D[2][1], _2D[2][2] - rhs._2D[2][2], _2D[2][3] - rhs._2D[2][3],
		_2D[3][0] - rhs._2D[3][0], _2D[3][1] - rhs._2D[3][1], _2D[3][2] - rhs._2D[3][2], _2D[3][3] - rhs._2D[3][3]
	};
}

Matrix4 & Matrix4::operator-=(const Matrix4& rhs)
{
	*this = *this - rhs;

	return *this;
}

Matrix4 & Matrix4::operator=(const Matrix4& rhs)
{
	axes[0] = rhs.axes[0];
	axes[1] = rhs.axes[1];
	axes[2] = rhs.axes[2];
	axes[3] = rhs.axes[3];

	return *this;
}

void Matrix4::setRotateX(const float& rotation)
{
	_2D[1][1] = cos(rotation);
	_2D[1][2] = sin(rotation);
	_2D[2][1] = -sin(rotation);
	_2D[2][2] = cos(rotation);
}

void Matrix4::setRotateY(const float& rotation)
{
	_2D[0][0] = cos(rotation);
	_2D[0][2] = -sin(rotation);
	_2D[2][0] = sin(rotation);
	_2D[2][2] = cos(rotation);
}

void Matrix4::setRotateZ(const float& rotation)
{
	_2D[0][0] = cos(rotation);
	_2D[0][1] = sin(rotation);
	_2D[1][0] = -sin(rotation);
	_2D[1][1] = cos(rotation);
}