
#pragma once
#include "Vec2.h"
class RectF
{
public:
	RectF() = default;
	RectF(float left_in, float top_in, float right_in, float bottom_in);
	RectF(Vec2& topLeft, float right_in, float bottom_in);
	RectF(Vec2& topLeft, Vec2& topRight);
	~RectF();

	

	float left;
	float right;
	float top;
	float bottom;
};
