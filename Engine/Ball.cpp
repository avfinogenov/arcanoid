#include "Ball.h"





Ball::Ball(Vec2& pos_in, Vec2& vel_in)
	:pos(pos_in),
	vel(vel_in)
	
{
	

}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

void Ball::Draw(Graphics & gfx)
{
	RectF rectOfBall(pos, 16.0f, 16.0f);
	gfx.DrawRect(rectOfBall, color);
}

Ball::~Ball()
{
}

void Ball::Update(float dt)
{
	pos += vel*dt;
}

Vec2 Ball::GetPos()
{
	return pos;
}

RectF Ball::GetRect()
{
	return RectF::FromCenter(pos,width,width);
}
