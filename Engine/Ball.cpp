#include "Ball.h"



//Ball::Ball()
//{
//}


Ball::Ball(Vec2 pos_in, Vec2 vel_in)
{
	pos = pos_in;
	vel = vel_in;
}

Ball::~Ball()
{
}

void Ball::ChangeOtherBool(bool *ex)
{

	*ex = true;
}

void Ball::Update(float dt)
{
	pos =pos + vel*dt;
}

void Ball::Draw(Graphics & gfx)
{

	gfx.DrawRect(GetReckt(), c);
}

void Ball::CheckCollWalls(RectF walls_in)
{
	RectF rect = GetReckt();
	if (rect.left<=walls_in.left)
	{
		pos.x += walls_in.left - rect.left;
		ReboundX();
	}
	if (rect.right >= walls_in.right)
	{
		pos.x += walls_in.right - rect.right;
		ReboundX();
	}
	if (rect.top <= walls_in.top)
	{
		pos.y += walls_in.top - rect.top;
		ReboundY();
	}
	if (rect.bottom >= walls_in.bottom)
	{
		pos.y += walls_in.bottom - rect.bottom;
		ReboundY();
	}
	
}

void Ball::CheckBricks(Brick b)
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

RectF Ball::GetReckt()
{

	return RectF::FromCenter(pos, 8,8);
}
