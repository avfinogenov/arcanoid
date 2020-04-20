
#pragma once
#include "Vec2.h"
class RectF
{
public:
	RectF() = default;
	RectF(float left_in, float top_in, float right_in, float bottom_in);
	RectF(Vec2& topLeft, float right_in, float bottom_in);
	RectF(Vec2& topLeft, Vec2& topRight);
	static RectF FromCenter(Vec2& center, float halfWidth, float halfHight);
	Vec2 GetCenter();
	bool IsOverlappinWith(RectF& other);
	

	float left;
	float right;
	float top;
	float bottom;
};
