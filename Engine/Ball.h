#pragma once
#include "Brick.h"
#include "Graphics.h"
class Ball
{
public:
	Ball(Vec2 pos_in, Vec2 vel_in);
	~Ball();
	void ChangeOtherBool(bool *ex);
	void Update(float dt);
	void Draw(Graphics& gfx);
	bool CheckCollWalls(RectF walls_in);
	RectF GetReckt();
	Vec2 pos;
	Vec2 vel;
	Vec2 size = Vec2(16, 16);
	Color c = Color(255, 255, 0);
};

