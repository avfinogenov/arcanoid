#include "RectF.h"

RectF::RectF(float l, float r, float t, float b)
{
	left = l;
	right = r;
	top = t;
	bottom = b;
}

RectF::RectF(Vec2 top_left, Vec2 bot_right)
	:RectF(top_left.x, top_left.x + bot_right.x, top_left.y, top_left.y + bot_right.y)
{
}

bool RectF::IsCollided(RectF other)
{
	bool b1, b2, b3, b4;
	b1 = left > other.right;
	b2 = right > other.left;
	b3 = top > other.bottom;
	b4 = bottom > other.top;
	return left>other.right && right>other.left && top>other.bottom && bottom>other.top;
}

RectF RectF::FromCenter(Vec2 & center, float halfWidth, float halfHight)
{
	return RectF(center.x-halfWidth, center.x+halfWidth, center.y-halfHight, center.y+halfHight);
}
