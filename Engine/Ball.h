#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"
class Ball
{
public:
	Ball() = default;
	Ball(Vec2 pos_in, Vec2 vel_in, Graphics& gfx);
	~Ball();
	Graphics & gfx;
	Color color;
	RectF rect;
	float width;
	float hight;
	Vec2 vel;
	Vec2 pos;
	//RectF rect(pos, width, hight);
	
};

