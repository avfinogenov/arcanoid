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
