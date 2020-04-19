#include "Brick.h"





Brick::Brick(RectF & rect_in)
{
	rect.left = rect_in.left;
	rect.top = rect_in.top;
	rect.right = rect_in.right;
	rect.bottom = rect_in.bottom;

}

void Brick::Draw(Graphics & gfx)
{
	if (!isDestroed)
	{
		gfx.DrawRect(rect, c);
	}
}

bool Brick::DoBallCollision(Ball & ball)
{
	if (!isDestroed && rect.IsOverlappinWith(ball.GetRect()))
	{
		ball.ReboundY();
		isDestroed = true;
		return true;
	}

	return false;
}


Brick::~Brick()
{
}
