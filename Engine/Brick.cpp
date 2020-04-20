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

bool Brick::CheckBallCollision(Ball & ball)
{
	return !isDestroed && rect.IsOverlappinWith(ball.GetRect());
}

void Brick::ExecuteBallCollision(Ball & ball)
{
	
		if (ball.pos.x >= rect.left && ball.pos.x <= rect.right)
		{
			ball.ReboundY();
		}
		else {
			ball.ReboundX();
		}
		isDestroed = true;
	

}


Brick::~Brick()
{
}
