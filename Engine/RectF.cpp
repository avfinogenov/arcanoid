#include "RectF.h"






RectF::RectF(float x_in, float y_in, float width_in, float hight_in)
{
	left = x_in;
	top = y_in;
	right = width_in;
	bottom = hight_in;
}

RectF::RectF(Vec2 & v_in, float width_in, float hight_in)
{
	RectF(v_in.x, v_in.y, width_in, hight_in);
}

RectF::RectF(Vec2 & pos_in, Vec2 & dim_in)
{
	RectF(pos_in.x, pos_in.y, dim_in.x, dim_in.y);
}

RectF::~RectF()
{
}
