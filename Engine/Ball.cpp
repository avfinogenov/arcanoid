#include "Ball.h"





Ball::Ball(Vec2 pos_in, Vec2 vel_in)
	:pos(pos_in),
	vel(vel_in)
{
	RectF rect(pos_in, width, hight);
}

void Ball::Draw(Graphics & gfx)
{
	gfx.DrawRect(rect, color);
}

Ball::~Ball()
{
}

void Ball::Update(float dt)
{
	pos = vel*dt;
}
