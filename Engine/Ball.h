#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"
class Ball
{
public:
	Ball() = default;
	Ball(Vec2 pos_in, Vec2 vel_in);

	void Draw(Graphics& gfx);
	~Ball();
	
	Color color=Colors::Yellow;
	RectF rect;
	float width=16.0f;
	float hight=16.0f;
	Vec2 vel;
	Vec2 pos;
	//RectF rect(pos, width, hight);
	
};

