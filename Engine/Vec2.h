#pragma once
class Vec2
{

public:
	float x;
	float y;
	Vec2() = default;
	Vec2(float x_in, float y_in);
	Vec2 operator+(const Vec2& rhs) const;
	Vec2 operator-(const Vec2& rhs) const;
	Vec2& operator+=(const Vec2& rhs);
	Vec2 operator*(float rhs) const;
	Vec2& operator*=(float rhs);
	float GetLength();
	float GetLengthSqrt();
	Vec2& Normakuze();
	Vec2 GetNormalized(); 
	~Vec2();
};
