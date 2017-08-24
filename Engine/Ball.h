#pragma once
#include "Vec2.h"
#include "RectF.h"
class Ball
{
public:
	Ball() = default;
	~Ball();

	float width;
	float hight;
	Vec2 vel;
	Vec2 pos;
	RectF rect(pos, width, hight);
	
};

