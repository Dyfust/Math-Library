#include "Vector2.h"
#include <cmath>

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}


Vector2::~Vector2()
{

}

Vector2::operator float*()
{
	return data;
}

Vector2::operator const float*() const
{
	return data;
}

float& Vector2::operator[] (const int index) 
{
	return data[index];
}

Vector2 Vector2::operator+ (Vector2& rhs) const
{
	return Vector2(this->x + rhs.x, this->y + rhs.y);
}

Vector2 Vector2::operator- (Vector2& rhs) const
{
	return Vector2(this->x - rhs.x, this->y - rhs.y);
}

Vector2 Vector2::operator* (float& scalar) const
{
	return Vector2(this->x * scalar, this->y * scalar);
}
Vector2 Vector2::operator/ (float& scalar) const
{
	return Vector2(this->x / scalar, this->y / scalar);
}

Vector2& Vector2::operator+= (Vector2& rhs)
{	
	x += rhs.x;
	y += rhs.y;

	return *this;
}		

Vector2& Vector2::operator-= (Vector2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;

	return *this;
}

Vector2& Vector2::operator*= (float& scalar)
{
	x *= scalar;
	y *= scalar;

	return *this;
}

Vector2& Vector2::operator/= (float& scalar) 
{
	x /= scalar;
	y /= scalar;

	return *this;
}

Vector2& Vector2::operator= (Vector2& rhs) 
{
	x = rhs.x;
	y = rhs.y;

	return *this;
}

float Vector2::magnitude() const
{
	return sqrt(x*x + y*y);
}

float Vector2::square_magnitude() const 
{
	return x * x + y * y;
}

Vector2 Vector2::normalized() const
{
	float mag = magnitude();
	return Vector2(this->x / mag, this->y / mag);
}

float Vector2::dot(Vector2& lhs) const
{
	x * lhs.x + y * lhs.y;
}
