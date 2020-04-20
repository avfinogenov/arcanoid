#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"
class Ball
{
public:
	Ball() = default;
	Ball(Vec2& pos_in, Vec2& vel_in);
	void DoWallCollison(RectF& walls)
	{
		RectF rect=RectF::FromCenter(pos, 8.0f, 8.0f);
		if (rect.left<walls.left) {
			pos.x += walls.left - rect.left;
			ReboundX();
		}
		if (rect.right>walls.right) {
			pos.x -= rect.right - walls.right;
			ReboundX();
		}
		if (rect.top<walls.top) {
			pos.y += walls.top - rect.top;
			ReboundY();
		}
		if (rect.bottom > walls.bottom) {
			pos.y -= rect.bottom - walls.bottom;
			ReboundY();
		}

	}
	void ReboundX();
	void ReboundY();
//	Ball(float posX_in, float posY_in, float velX_in, float velY_in);
	void Draw(Graphics& gfx);
	~Ball();
	void Update(float dt);
	Vec2 GetPos();
	Color color=Colors::Yellow;
	//RectF rect;
	static constexpr float width=16.0f;
	float hight=16.0f;
	Vec2 vel;
	Vec2 pos;
	RectF GetRect();
	//RectF rect(pos, width, hight);
	
};

