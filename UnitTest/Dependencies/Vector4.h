#ifndef VECTOR4_H
#define VECTOR4_H

class Vector4
{
public:
	Vector4();
	Vector4(float x, float y, float z, float w);
	~Vector4();

	// Different ways of identifying the same data.
	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		struct
		{
			float r;
			float g;
			float b;
			float a;
		};
		float data[4];
	};

	// Overloaded subscript operator to access the different elements in the vector.
	float& operator[] (const int index);

	// Overloaded float* operator to get a pointer to the array of elements contained in the vector. (tbh, im not really sure what this does to be exact)
	explicit operator float* ();
	explicit operator const float* () const;

	// Overloaded arithmetic operations with scalars & vectors. (You never multiple/divide a vector by another vector so they're excluded)
	Vector4 operator+ (const Vector4& rhs) const;
	Vector4 operator- (const Vector4& rhs) const;
	Vector4 operator* (const float scalar) const;
	Vector4 operator/ (const float scalar) const;
	Vector4& operator+= (const Vector4& rhs);
	Vector4& operator-= (const Vector4& rhs);
	Vector4& operator*= (const float scalar);
	Vector4& operator/= (const float scalar);

	// Overloaded assignment operator.
	Vector4& operator= (const Vector4& rhs);

	// Returns the square rooted magnitude of the vector.
	void normalise();

	// Returns the squared magnitude of the vector.
	Vector4 normalized() const;

	// Returns a normalized instance of this vector.
	float square_magnitude() const;

	// Normalizes the vector.
	float magnitude() const;

	// Returns the dot product of this and rhs.
	float dot(Vector4& rhs) const;

	// Returns the cross product between the two vectors. (A vector that is perpendicular to the two)
	Vector4 cross(Vector4& rhs) const;

};

// Overloaded multiplication operator where the lhs is a float.
Vector4 operator* (const float lhs, const Vector4& rhs);
#endif // VECTOR4_H