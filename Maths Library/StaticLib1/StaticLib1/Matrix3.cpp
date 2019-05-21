#include "Matrix3.h"


Matrix3::Matrix3()
{
	x_axis[0] = 1.0f;
	x_axis[1] = 0.0f;
	x_axis[2] = 0.0f;

	y_axis[0] = 0.0f;
	y_axis[1] = 1.0f;
	y_axis[2] = 0.0f;

	position[0] = 0.0f;
	position[1] = 0.0f;
	position[2] = 1.0f;
}


Matrix3::Matrix3(Vector3 right, Vector3 forward, Vector3 position)
{
	this->right = right;
	this->forward = forward;
	this->position = position;
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

float* Matrix3::operator[] (const int index_a)
{
	return _2D[index_a];
}

Matrix3 Matrix3::operator+ (Matrix3& rhs)
{
	return Matrix3(right + rhs.right, forward + rhs.forward, position + rhs.position);
}

Matrix3 Matrix3::operator- (Matrix3& rhs)
{
	return Matrix3(right - rhs.right, forward - rhs.forward, position - rhs.position);
}

Matrix3 Matrix3::operator* (Matrix3& rhs)
{
	Matrix3 matrix;

	matrix._2D[0][0] = _2D[0][0] * rhs._2D[0][0] + _2D[1][0] * rhs._2D[0][1] + _2D[2][0] * rhs._2D[0][2]; 
	matrix._2D[0][1] = _2D[0][1] * rhs._2D[0][0] + _2D[1][1] * rhs._2D[0][1] + _2D[2][1] * rhs._2D[0][2]; 
	matrix._2D[0][2] = _2D[0][2] * rhs._2D[0][0] + _2D[1][2] * rhs._2D[0][1] + _2D[2][2] * rhs._2D[0][2];

	matrix._2D[1][0] = _2D[0][0] * rhs._2D[1][0] + _2D[1][0] * rhs._2D[1][1] + _2D[2][0] * rhs._2D[1][2]; 
	matrix._2D[1][1] = _2D[0][0] * rhs._2D[1][0] + _2D[1][0] * rhs._2D[1][1] + _2D[2][0] * rhs._2D[1][2]; // DO THIS
	matrix._2D[1][2] = _2D[0][0] * rhs._2D[1][0] + _2D[1][0] * rhs._2D[1][1] + _2D[2][0] * rhs._2D[1][2]; // DO THIS
}