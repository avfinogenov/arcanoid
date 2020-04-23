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

bool Ball::CheckCollWalls(RectF walls_in)
{
	RectF rect = GetReckt();
	if (rect.IsCollided(walls_in))
	{

	}
	return false;
}

RectF Ball::GetReckt()
{

	return RectF(pos, size);
}
