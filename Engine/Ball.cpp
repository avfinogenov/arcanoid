#include "Ball.h"





Ball::Ball(Vec2& pos_in, Vec2& vel_in)
	:pos(pos_in),
	vel(vel_in),
	rect(pos_in.x, pos_in.y,( pos_in.x+16.0f),(pos_in.y+ 16.0f))
{
	

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
