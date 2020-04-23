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
	ball(Vec2(300, 300), Vec2(300, 300))
	
	
{
	InitBriks();
	InitMap();
}

void Game::Go()
{
	gfx.BeginFrame();	
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0.0f)
	{
		const float dt = std::min(0.0025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	
	ComposeFrame();
	
	gfx.EndFrame();
}

void Game::InitBriks()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < nRow; j++)
		{

			Vec2 posOfBriks;

			posOfBriks.x = (sizeOfBrik.x*float(i)) + offset.x;
			posOfBriks.y = offset.y + (sizeOfBrik.y*(float)j);
			bricks[i][j].rect = RectF(posOfBriks, sizeOfBrik);
			}
		}
}
void Game::InitMap()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			map[i][j].x = (i*offset.x + (i + 1)*offset.x) / 2;
			map[i][j].y = (j*offset.y + (j + 1)*offset.y) / 2;
			
		}
	}
	

}
//void Function()
//{
//	//setbricknumber;
//	
//}
int Game::MapGetPosX(Vec2 pos)
{
	return (int)((pos.x - 10) / 20);
}
int Game::MapGetPosY(Vec2 pos)
{
	return (int)((pos.y - 10) / 20);
}
void Game::UpdateModel(float dt)
{
	bool *pBoll;
	pBoll = &(bricks[0][0].isDestroyed);
	ball.ChangeOtherBool(pBoll);
	if (bricks[0][0].isDestroyed)
	{
		gfx.PutPixel(20, 400, 255, 255, 255);
	}
	
	ball.Update(dt);
	
	
}

void Game::ComposeFrame()
{
	
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < nRow; j++)
		{
			bricks[i][j].DrawBrick(gfx);
		}
	}
	ball.Draw(gfx);
	// some things are just too perfect and pure for
	// this cruel world...
}
