#pragma once
class Vector2
{
public:
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

	Vector2 operator+ (Vector2& rhs) const;
	Vector2 operator- (Vector2& rhs) const;
	Vector2 operator* (float& scalar) const;
	Vector2 operator/ (float& scalar) const;
	
	Vector2& operator+= (Vector2& rhs);
	Vector2& operator-= (Vector2& rhs);
	Vector2& operator*= (float& scalar);
	Vector2& operator/= (float& scalar);

	Vector2& operator= (Vector2& rhs);

	float magnitude() const;
	float square_magnitude() const;

	Vector2 normalized() const;

	float dot(Vector2& lhs) const;
};

