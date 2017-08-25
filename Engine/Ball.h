#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"
class Ball
{
public:
	Ball() = default;
	Ball(Vec2& pos_in, Vec2& vel_in);
//	Ball(float posX_in, float posY_in, float velX_in, float velY_in);
	void Draw(Graphics& gfx);
	~Ball();
	void Update(float dt);
	Color color=Colors::Yellow;
	RectF rect;
	float width=16.0f;
	float hight=16.0f;
	Vec2 vel;
	Vec2 pos;
	//RectF rect(pos, width, hight);
	
};

