#pragma once
#include"RectF.h"
#include"Colors.h"
#include"Graphics.h"
class Brick
{
public:
	Brick()=default;
	Brick(RectF& rect);
	void Draw(Graphics & gfx);
	RectF rect;
	Color c = Colors::White;
	bool isDestroed = false;


	~Brick();
};

