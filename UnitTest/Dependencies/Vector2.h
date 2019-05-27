#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	union
	{
		struct 
		{
			float x;
			float y;
		};

		float data[2];
	};

	float& operator[] (const int index);

	operator float*();

	operator const float*() const;

	Vector2 operator+ (const Vector2& rhs) const;
	Vector2 operator- (const Vector2& rhs) const;
	Vector2 operator* (const float scalar) const;
	Vector2 operator/ (const float scalar) const;
	
	Vector2& operator+= (const Vector2& rhs);
	Vector2& operator-= (const Vector2& rhs);
	Vector2& operator*= (const float scalar);
	Vector2& operator/= (const float scalar);

	Vector2& operator= (const Vector2& rhs);

	float magnitude() const;
	float square_magnitude() const;

	Vector2 normalized() const;
	void normalise();

	float dot(Vector2& lhs) const;
};

Vector2 operator * (const float lhs, const Vector2& rhs);