#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	// Different ways of identifying the same data.
	union
	{
		struct 
		{
			float x;
			float y;
		};

		float data[2];
	};

	// Overloaded subscript operator to access the different elements in the vector.
	float& operator[] (const int index);

	// Overloaded float* operator to get a pointer to the first axis (tbh, im not really sure what this does to be exact)
	operator float*();
	operator const float*() const;

	// Overloaded arithmetic operations with scalars & vectors. (You never multiple/divide a vector by another vector so they're excluded)
	Vector2 operator+ (const Vector2& rhs) const;
	Vector2 operator- (const Vector2& rhs) const;
	Vector2 operator* (const float scalar) const;
	Vector2 operator/ (const float scalar) const;
	Vector2& operator+= (const Vector2& rhs);
	Vector2& operator-= (const Vector2& rhs);
	Vector2& operator*= (const float scalar);
	Vector2& operator/= (const float scalar);

	// Overloaded assignment operator.
	Vector2& operator= (const Vector2& rhs);

	// Returns the square rooted magnitude of the vector.
	float magnitude() const;

	// Returns the squared magnitude of the vector.
	float square_magnitude() const;

	// Returns a normalized instance of this vector.
	Vector2 normalized() const;

	// Normalizes the vector.
	void normalise();

	// Returns the dot product of this and rhs.
	float dot(Vector2& rhs) const;
};

// Overloaded multiplication operator where the lhs is a float.
Vector2 operator * (const float lhs, const Vector2& rhs);