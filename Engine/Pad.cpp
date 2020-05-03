#include "Pad.h"



//Pad::Pad()
//{
//}


Pad::Pad(Vec2 pos_in)
{
	
	pos = pos_in;
	vel =Vec2(300,0);
}

void Pad::DrawPad(Graphics & gfx)
{
	gfx.DrawRect(RectF::FromCenter(pos,50,15), c);
}

void Pad::Update(float dt, Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos = pos - vel*dt;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos = pos + vel*dt;
	}
	
}

void Pad::CheckWalls(RectF walls)
{	
	RectF tmp = RectF::FromCenter(pos, 50, 15);
	if (tmp.left < walls.left)
	{
		pos.x = pos.x + walls.left - tmp.left;
	}
	if (tmp.right > walls.right)
	{
		pos.x = pos.x - tmp.right + walls.right;
	}
	
}

void Pad::CheckBall(Ball* ball)
{
	Ball b;
	b = *ball;
	if ( b.GetReckt().IsCollided(GetRect())&& !isCooldown)
	{
		if ((b.pos.x < GetRect().left) || (b.pos.x > GetRect().right))
		{
			if (signbit(b.pos.x - GetRect().GetCenter().x) == signbit(b.vel.x))
			{
				ball->ReboundY();
			}
			else
			{
				ball->ReboundX();
			}

		}
		else
		{
			ball->ReboundY();
		}
		isCooldown = true;


	}
}

RectF Pad::GetRect()
{
	return RectF::FromCenter(pos,50,15);
}

void Pad::ResetCooldown()
{
	isCooldown = false;
}

Pad::~Pad()
{
}
