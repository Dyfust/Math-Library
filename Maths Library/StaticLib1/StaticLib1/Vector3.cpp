#include "Vector3.h"

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{
}

float& Vector3::operator[](const int index)
{
	return data[index];
}

Vector3::operator float*()
{
	return data;
}

Vector3::operator const float*() const
{
	return data;
}

Vector3 Vector3::operator+ (const Vector3& rhs) const
{
	return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3 Vector3::operator- (const Vector3& rhs) const
{
	return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3 Vector3::operator* (const float scalar) const
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator/ (const float scalar) const
{
	return Vector3(x / scalar, y / scalar, z / scalar);
}

Vector3& Vector3::operator+= (const Vector3 rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;

	return *this;
}

Vector3& Vector3::operator-= (const Vector3 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;

	return *this;
}

Vector3& Vector3::operator*= (const float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;

	return *this;
}

Vector3& Vector3::operator/= (const float scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;

	return *this;
}

Vector3& Vector3::operator= (const Vector3& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;

	return *this;
}

float Vector3::square_magnitude() const
{
	return (x*x + y * y + z * z);
}

float Vector3::magnitude() const
{
	return sqrt(x*x + y * y + z * z);
}

void Vector3::normalise()
{
	float mag = magnitude();

	x /= mag;
	y /= mag;
	z /= mag;
}

Vector3 Vector3::normalized() const
{
	float mag = magnitude();
	return Vector3(x / mag, y / mag, z / mag);
}

float Vector3::dot(Vector3& rhs) const
{
	return (x*rhs.x + y * rhs.y + z * rhs.z);
}

Vector3 Vector3::cross(Vector3& rhs) const
{
	return Vector3(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
}

Vector3 operator*(const float lhs, const Vector3 rhs)
{
	return Vector3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}