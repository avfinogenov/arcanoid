#pragma once
#include"RectF.h"
#include"Colors.h"
#include"Graphics.h"
#include "Ball.h"
class Brick
{
public:
	Brick()=default;
	Brick(RectF& rect);
	void Draw(Graphics & gfx);
	bool CheckBallCollision(Ball& ball);
	void ExecuteBallCollision(Ball& ball);
	RectF rect;
	Color c = Colors::White;
	bool isDestroed = false;


	~Brick();
};

