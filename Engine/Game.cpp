/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(440.0f, 300.0f), Vec2(300.0f, 300.0f)),
	walls(0.0f, 0.0f, (float)gfx.ScreenWidth, (float)gfx.ScreenHeight),
	pad(Vec2(400,500), 50, 15)
	//briks[]()
{
	InitBriks();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
	//InitBriks();
}

void Game::InitBriks()
{
	for (int i = 0;i < numberOfBricks;i++)
		for (int j = 0;j < numberOfLayers;j++)
		{

			{
				float tmp = float(i);
				posOfBriks[i][j].x = (sizeOfBrik.x*tmp) + offset.x;
				posOfBriks[i][j].y = offset.y+(sizeOfBrik.y*(float)j);
				brick[i][j].rect = RectF(posOfBriks[i][j], sizeOfBrik);
			}
		}
}

void Game::ChangeVelocityBall()
{
	
	if (wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		ball.vel.x = ball.vel.x * 1.1;
		ball.vel.y = ball.vel.y * 1.1;
	}
	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		ball.vel.x = ball.vel.x / 1.1;
		ball.vel.y = ball.vel.y / 1.1;
	}
}

void Game::UpdateModel()
{
	float dt = ft.Mark();
	ball.Update(dt);
	ChangeVelocityBall();
	ball.DoWallCollison(walls);
	pad.Update(wnd.kbd, dt);
	pad.DoWallCollision(walls);
	pad.DoBallCollision(ball);
	bool isCol = false;
	float curColDistSq;
	int curColI, curColj;
	float newColDistSq;
	for (int i = 0; i < (numberOfBricks); i++)
	{
		
		for (int j = 0; j < numberOfLayers; j++)
		{
			if (brick[i][j].CheckBallCollision(ball))
			{
				newColDistSq = (ball.GetPos() - brick[i][j].rect.GetCenter()).GetLengthSqrt();
				if (isCol)
				{
					if (newColDistSq < curColDistSq)
					{
						curColDistSq = newColDistSq;
						curColI = i;
						curColj = j;
					}
				}
				else
				{
					isCol = true;
					curColDistSq = newColDistSq;
					curColI = i;
					curColj = j;
				}
			}
			if (isCol)
			{
				brick[curColI][curColj].ExecuteBallCollision(ball);
			}
		
		
		
		
		
		
		}
		
	}
	//if (brick[1][1].DoBallCollision(ball))
	

}

void Game::DrawBriks(Graphics & gfx)
{
	for (int i = 0; i < numberOfBricks;i++)
		for (int j = 0; j < numberOfLayers;j++)
		{
			{
				if (!brick[i][j].isDestroed)
				{
					gfx.DrawBrick(brick[i][j].rect, Colors::White);
				}
			}
		}
}

void Game::ComposeFrame()
{
	pad.Draw(gfx);
	ball.Draw(gfx);
	DrawBriks(gfx);
	// some things are just too perfect and pure for
	// this cruel world...
}
