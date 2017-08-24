#include "Ball.h"





Ball::Ball(Vec2 pos_in, Vec2 vel_in, Graphics & gfx)
	:pos(pos_in),
	vel(vel_in),
	gfx(gfx)
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
