#pragma once
#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"
#include "Keyboard.h"
class Pad
{
	
public:
	Pad() = default;
	Pad(Vec2 pos_in);
	void DrawPad(Graphics& gfx);
	void Update(float dt, Keyboard& kbd);
	void CheckWalls(RectF walls);
	void CheckBall(Ball *ball);
	RectF GetRect();
	~Pad();
	Vec2 pos;
	//RectF rect;
	Color c = Color(255, 0, 0);
	Vec2 vel;
	bool isCooldown = false;
	
};

