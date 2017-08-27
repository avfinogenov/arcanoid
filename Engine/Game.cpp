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
	ball(Vec2(400.0f, 300.0f), Vec2(500.0f, 500.0f)),
	walls(0.0f, 0.0f, (float)gfx.ScreenWidth, (float)gfx.ScreenHeight)
	//briks[]()
{
	//InitBriks();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
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

void Game::UpdateModel()
{
	float dt = ft.Mark();
	ball.Update(dt);
	ball.DoWallCollison(walls);
	InitBriks();
}

void Game::DrawBriks(Graphics & gfx)
{
	for (int i = 0; i < numberOfBricks;i++)
		for (int j = 0; j < numberOfLayers;j++)
		{
			{
				gfx.DrawBrick(brick[i][j].rect, Colors::White);
			}
		}
}

void Game::ComposeFrame()
{
	ball.Draw(gfx);
	DrawBriks(gfx);
	// some things are just too perfect and pure for
	// this cruel world...
}
