#include "Pad.h"



//Pad::Pad()
//{
//}


Pad::Pad(RectF rect_in, Vec2 vel_in)
{
	rect = rect_in;
	pos = rect.GetCenter();
	vel = vel_in;
}

void Pad::DrawPad(Graphics & gfx)
{
	gfx.DrawRect(rect, c);
}

void Pad::Update(float dt, Keyboard kbd)
{
	if (kbd.KeyIsPressed(MK_LBUTTON))
	{
		pos = pos - vel*dt;
	}
	if (kbd.KeyIsPressed(MK_RBUTTON))
	{
		pos = pos + vel*dt;
	}
}

Pad::~Pad()
{
}
