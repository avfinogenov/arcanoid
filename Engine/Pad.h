#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"
#include "Keyboard.h"
class Pad
{
public:
	Pad( Vec2& pos_in, float half_hight_in, float half_width_in);
	void Draw(Graphics& gfx);
	void DoWallCollision(RectF& walls);
	bool DoBallCollision(Ball& ball);
	void Update(Keyboard& kbd, float dt);
	RectF GetRect();


	


	~Pad();
private:
	Vec2 pos;
	Vec2 vel;
	float half_hight;
	float half_width;
	float speed = 300.0f;
	Color color = Colors::Red;
};

