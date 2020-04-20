#include "Pad.h"



//Pad::Pad()
//{
//}


Pad::Pad(Vec2 & pos_in, float half_hight_in, float half_width_in)
	:pos(pos_in),
	half_hight(half_hight_in),
	half_width(half_width_in)
{


}

void Pad::Draw(Graphics & gfx)
{
	gfx.DrawRect(GetRect(), color);
}
void Pad::DoWallCollision(RectF & walls)
{
	RectF rect = GetRect();

	if (rect.left<walls.left) {
		pos.x += walls.left - rect.left;
		
	}
	if (rect.right>walls.right) {
		pos.x -= rect.right - walls.right;
		
	}
	
	
}

bool Pad::DoBallCollision(Ball & ball)
{
	RectF rect = GetRect();
	if (rect.IsOverlappinWith(ball.GetRect()))
	{

		ball.ReboundY();
		return true;
	}
	return false;
}

void Pad::Update(Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= speed*dt;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += speed*dt;
	}

}

RectF Pad::GetRect()
{
	return RectF::FromCenter(pos, half_hight, half_width);
}

Pad::~Pad()
{
}
