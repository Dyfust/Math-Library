#ifndef VECTOR4_H
#define VECTOR4_H

class Vector4
{
public:
	Vector4(float x, float y, float z, float w);
	~Vector4();

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

	explicit operator float* ();
	explicit operator const float* () const;

	float& operator[] (const int index);

	Vector4 operator+ (Vector4& rhs);
	Vector4 operator- (Vector4& rhs);
	Vector4 operator* (float& scalar);
	Vector4 operator/ (float& scalar);

	Vector4& operator+= (Vector4& rhs);
	Vector4& operator-= (Vector4& rhs);
	Vector4& operator*= (float& scalar);
	Vector4& operator/= (float& scalar);

	void normalize();
	Vector4 normalized() const;

	float square_magnitude() const;
	float magnitude() const;

	float dot(Vector4& rhs) const;
	Vector4 cross(Vector4& rhs) const;

};

#endif // VECTOR4_H