#include "Matrix3.h"

Matrix3::Matrix3(float one, float two, float three, float four, float five, float six, float seven, float eight, float nine) : 
	_1D{ one,  two, three, four, five, six, seven, eight, nine }
{
}

Matrix3::Matrix3(Vector3 right, Vector3 forward, Vector3 position) : 
	right(right), forward(forward), position(position)
{
}

Matrix3::Matrix3(float* x_axis, float* y_axis, float* translation)
{
	this->x_axis[0] = x_axis[0];
	this->x_axis[1] = x_axis[1];
	this->x_axis[2] = x_axis[2];

	this->y_axis[0] = y_axis[0];
	this->y_axis[1] = y_axis[1];
	this->y_axis[2] = y_axis[2];

	this->translation[0] = translation[0];
	this->translation[1] = translation[1];
	this->translation[2] = translation[2];
}

Matrix3::~Matrix3()
{

}

Matrix3::operator float*() 
{
	return _1D;
}

Matrix3::operator const float*() const
{
	return _1D;
}

Vector3& Matrix3::operator[] (const int index_a)
{
	return axes[index_a];
}

Matrix3 Matrix3::operator+ (const Matrix3& rhs) const
{
	return Matrix3(right + rhs.right, forward + rhs.forward, position + rhs.position);
}

Matrix3 Matrix3::operator- (const Matrix3& rhs) const
{
	return Matrix3(right - rhs.right, forward - rhs.forward, position - rhs.position);
}

Matrix3 Matrix3::operator* (const Matrix3& rhs) const
{
	Matrix3 matrix;

	matrix._2D[0][0] = _2D[0][0] * rhs._2D[0][0] + _2D[1][0] * rhs._2D[0][1] + _2D[2][0] * rhs._2D[0][2]; 
	matrix._2D[0][1] = _2D[0][1] * rhs._2D[0][0] + _2D[1][1] * rhs._2D[0][1] + _2D[2][1] * rhs._2D[0][2]; 
	matrix._2D[0][2] = _2D[0][2] * rhs._2D[0][0] + _2D[1][2] * rhs._2D[0][1] + _2D[2][2] * rhs._2D[0][2];

	matrix._2D[1][0] = _2D[0][0] * rhs._2D[1][0] + _2D[1][0] * rhs._2D[1][1] + _2D[2][0] * rhs._2D[1][2]; 
	matrix._2D[1][1] = _2D[0][1] * rhs._2D[1][0] + _2D[1][1] * rhs._2D[1][1] + _2D[2][1] * rhs._2D[1][2];
	matrix._2D[1][2] = _2D[0][2] * rhs._2D[1][0] + _2D[1][2] * rhs._2D[1][1] + _2D[2][2] * rhs._2D[1][2];

	matrix._2D[2][0] = _2D[0][0] * rhs._2D[2][0] + _2D[1][0] * rhs._2D[2][1] + _2D[2][0] * rhs._2D[2][2];
	matrix._2D[2][1] = _2D[0][1] * rhs._2D[2][0] + _2D[1][1] * rhs._2D[2][1] + _2D[2][1] * rhs._2D[2][2];
	matrix._2D[2][2] = _2D[0][2] * rhs._2D[2][0] + _2D[1][2] * rhs._2D[2][1] + _2D[2][2] * rhs._2D[2][2];
	
	return matrix;
}

Matrix3& Matrix3::operator+= (const Matrix3& rhs)
{
	right += rhs.right;
	forward += rhs.forward;
	position += rhs.position;

	return *this;
}

Matrix3& Matrix3::operator-= (const Matrix3& rhs) 
{
	forward -= rhs.forward;
	right -= rhs.right;
	position -= rhs.position;

	return *this;
}

Matrix3& Matrix3::operator*= (const Matrix3& rhs)
{
	_2D[0][0] = _2D[0][0] * rhs._2D[0][0] + _2D[1][0] * rhs._2D[0][1] + _2D[2][0] * rhs._2D[0][2];
	_2D[0][1] = _2D[0][1] * rhs._2D[0][0] + _2D[1][1] * rhs._2D[0][1] + _2D[2][1] * rhs._2D[0][2];
	_2D[0][2] = _2D[0][2] * rhs._2D[0][0] + _2D[1][2] * rhs._2D[0][1] + _2D[2][2] * rhs._2D[0][2];

	_2D[1][0] = _2D[0][0] * rhs._2D[1][0] + _2D[1][0] * rhs._2D[1][1] + _2D[2][0] * rhs._2D[1][2];
	_2D[1][1] = _2D[0][1] * rhs._2D[1][0] + _2D[1][1] * rhs._2D[1][1] + _2D[2][1] * rhs._2D[1][2]; // DO THIS
	_2D[1][2] = _2D[0][2] * rhs._2D[1][0] + _2D[1][2] * rhs._2D[1][1] + _2D[2][2] * rhs._2D[1][2]; // DO THIS

	_2D[2][0] = _2D[0][0] * rhs._2D[2][0] + _2D[1][0] * rhs._2D[2][1] + _2D[2][0] * rhs._2D[2][2];
	_2D[2][1] = _2D[0][1] * rhs._2D[2][0] + _2D[1][1] * rhs._2D[2][1] + _2D[2][1] * rhs._2D[2][2]; // DO THIS
	_2D[2][2] = _2D[0][2] * rhs._2D[2][0] + _2D[1][2] * rhs._2D[2][1] + _2D[2][2] * rhs._2D[2][2]; // DO THIS

	return *this;
}

Matrix3& Matrix3::operator=(const Matrix3& rhs)
{
	axes[0] = rhs.axes[0];
	axes[1] = rhs.axes[1];
	axes[2] = rhs.axes[2];

	return *this;
}

Vector3 Matrix3::operator* (const Vector3& rhs) const
{
	Vector3 result;

	result.x = _2D[0][0] * rhs.x + _2D[1][0] * rhs.y + _2D[2][0] * rhs.z;
	result.y = _2D[0][1] * rhs.x + _2D[1][1] * rhs.y + _2D[2][1] * rhs.z;
	result.z = _2D[0][2] * rhs.x + _2D[1][2] * rhs.y + _2D[2][2] * rhs.z;

	return result;
}

void Matrix3::setRotateX(const float& a_rotation)
{
	_2D[1][1] = cos(a_rotation);
	_2D[1][2] = sin(a_rotation);
	_2D[2][1] = -sin(a_rotation);
	_2D[2][2] = cos(a_rotation);
}

void Matrix3::setRotateY(const float& a_rotation)
{
	_2D[0][0] = cos(a_rotation);
	_2D[0][2] = -sin(a_rotation);
	_2D[2][0] = sin(a_rotation);
	_2D[2][2] = cos(a_rotation);
}

void Matrix3::setRotateZ(const float& a_rotation)
{
	_2D[0][0] = cos(a_rotation);
	_2D[0][1] = sin(a_rotation);
	_2D[1][0] = -sin(a_rotation);
	_2D[1][1] = cos(a_rotation);
}