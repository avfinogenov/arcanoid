#pragma once
#include "RectF.h"
#include "Graphics.h"
class Brick
{
public:
	Brick() = default;
	Brick(RectF rect_in);
	void DrawBrick(Graphics& gfx);
	~Brick();
	RectF rect;
	Color c = Color(255, 255, 255);
	bool isDestroyed = false;






};

