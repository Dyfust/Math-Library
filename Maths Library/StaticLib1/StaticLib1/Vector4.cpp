#include "Vector4.h"
#include <cmath>

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::~Vector4()
{

}

explicit Vector4::operator float* () 
{
	return data;
}
explicit Vector4::operator const float* () const
{
	return data;
}

float& Vector4::operator[] (const int index) 
{
	return data[index];
}

Vector4 Vector4::operator+ (Vector4& rhs) 
{
	return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

Vector4 Vector4::operator- (Vector4& rhs) 
{
	return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

Vector4 Vector4::operator* (float& scalar) 
{
	return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}

Vector4 Vector4::operator/ (float& scalar) 
{
	return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
}

Vector4& Vector4::operator+= (Vector4& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;

	return *this;
}

Vector4& Vector4::operator-= (Vector4& rhs) 
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;

	return *this;
}

Vector4& Vector4::operator*= (float& scalar) 
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;

	return *this;
}

Vector4& Vector4::operator/= (float& scalar) 
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
	w /= scalar;

	return *this;
}

void Vector4::normalize()
{
	float mag = magnitude();

	x /= mag;
	y /= mag;
	z /= mag;
	w /= mag;
}

Vector4 Vector4::normalized() const
{
	float mag = magnitude();
	return Vector4(x / mag, y / mag, z / mag, w / mag);
}

float Vector4::square_magnitude() const
{
	return (x*x + y * y + z * z + w * w);
}

float Vector4::magnitude() const
{
	return sqrt(square_magnitude());
}

float Vector4::dot(Vector4& rhs) const
{
	return (x*rhs.x + y * rhs.y + z * rhs.z + w * rhs.w);
}

Vector4 Vector4::cross(Vector4& rhs) const
{
	return Vector4(y * rhs.z - z * rhs.y,
		z * rhs.x - x * rhs.z,
		x * rhs.y - y * rhs.x,
		w);
}
