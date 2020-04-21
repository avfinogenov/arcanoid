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


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
	
	
{/*
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < nRow; j++)
		{
			int x1tmp, x2tmp, y1tmp, y2tmp;
			x1tmp = i*xbrickSize;
			x2tmp = (i + 1)*xbrickSize;
			y1tmp = j*ybrickSize;
			y2tmp = (j + 1)*ybrickSize;
			RectF rect = RectF(x1tmp, x2tmp, y1tmp, y2tmp);
			bricks[i][j](rect);
		}
	}
*/
	InitBriks();
	
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
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < nRow; j++)
		{

			Vec2 posOfBriks[row][nRow];

			posOfBriks[i][j].x = (sizeOfBrik.x*float(i)) + offset.x;
			posOfBriks[i][j].y = offset.y + (sizeOfBrik.y*(float)j);
			bricks[i][j].rect = RectF(posOfBriks[i][j], sizeOfBrik);
			}
		}
}
void Game::UpdateModel()
{
	
}

void Game::ComposeFrame()
{
	
	 //Brick b = Brick(RectF(0, 10, 0, 10));
//	b1.DrawBrick(gfx);
	//b.DrawBrick(gfx);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < nRow; j++)
		{
			bricks[i][j].DrawBrick(gfx);
		}
	}

	// some things are just too perfect and pure for
	// this cruel world...
}
