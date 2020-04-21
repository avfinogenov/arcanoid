#include "Brick.h"






Brick::Brick(RectF rect_in)
{
	rect = rect_in;
}

void Brick::DrawBrick(Graphics& gfx)
{
	gfx.DrawRect(rect, c);
}

Brick::~Brick()
{
}
