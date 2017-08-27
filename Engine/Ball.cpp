#include "Ball.h"





Ball::Ball(Vec2& pos_in, Vec2& vel_in)
	:pos(pos_in),
	vel(vel_in)
	
{
	

}

void Ball::DoWallCollison(RectF& walls)
{
	RectF rect(pos, 16.0f, 16.0f);
	if (rect.left<walls.left){
		pos.x += walls.left - rect.left;
		ReboundX();
	}
	if(rect.right>walls.right){
		pos.x -= rect.right - walls.right;
		ReboundX();
	}
	if(rect.top<walls.top){
		pos.y += walls.top- rect.top ;
		ReboundY();
	}
	if (rect.bottom > walls.bottom) { 
		pos.y -= rect.bottom - walls.bottom;
		ReboundY(); 
	}
	
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

void Ball::Draw(Graphics & gfx)
{
	RectF rectOfBall(pos, 16.0f, 16.0f);
	gfx.DrawRect(rectOfBall, color);
}

Ball::~Ball()
{
}

void Ball::Update(float dt)
{
	pos += vel*dt;
}
