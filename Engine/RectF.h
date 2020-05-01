#pragma once
#include "Vec2.h"
class RectF
{
public:

	float left, right, top, bottom;

	RectF() = default;
	RectF(float l, float r, float t, float b);
	RectF(Vec2 top_left, Vec2 bot_right);
	bool IsCollided(RectF other);
	static RectF FromCenter(Vec2& center, float halfWidth, float halfHight);
	Vec2 GetCenter(RectF rect_in);



};