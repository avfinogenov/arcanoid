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

void Pad::Update(float dt, Keyboard kbd)
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

Pad::~Pad()
{
}
