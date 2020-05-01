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
	ball(Vec2(300, 300), Vec2(300, 300)),
	walls(RectF(0,800,0,600))
	
	
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
	//          for (int i = 0; i < 40; i++)
	//          {
	//          	for (int j = 0; j < 30; j++)
	//          	{
	//          		map[i][j].x = (i*offset.x + (i + 1)*offset.x) / 2;
	//          		map[i][j].y = (j*offset.y + (j + 1)*offset.y) / 2;
	//          		
	//          	}
	//          }
	

}
void Game::CheckBricks()
{
	float tmpX, tmpY;
	tmpX = (ball.pos.x - 10) / 20;
	tmpY = (ball.pos.y - 10) / 20;
	int nX, nY;
	nX = ((int)tmpX) / 2;
	nY = ((int)tmpY);
	// nX nY - position of a ball
	// check around 
	// вычислить рассто€ние до центра м€ча всех существующих кирпичей
	// найти кратчайшее рассто€ние и проверить на уничтожение
	//Vec2 result_distance=Vec2(0,0);
	distance=-1;
	a[0] =  0;
	a[1] = 0;
	int tmpi = nX - 1;
	int tmpj = nY - 1;
	for (int i = nX - 1; i < nX + 1; i++)
	{
		for (int j = nY - 1; j < nY + 1; j++)
		{
			
			GetDistance(i, j);
		}
	}
 tmpi = nX - 1;
 tmpj = nY - 1;
	if (distance >= 0)
	{
		if (bricks[a[0]][a[1]].rect.IsCollided(ball.GetReckt()))
		{
			bricks[a[0]][a[1]].isDestroyed = true;
			ball.ReboundY();
		}
	}

	//  if (nX < 19 && nY < 5)
	//  {
	//  	bricks[nX][nY].isDestroyed = true;
	//  }
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
void Game::GetDistance(int i, int j)
{
	if (i == 18 && j == 0)
	{
		int tmp=0;
	}
	if (i<=19 && j<5 && i>=0 && j>=0)
	{
		if (!bricks[i][j].isDestroyed)
		{
			float tmp = (bricks[i][j].rect.GetCenter() - ball.pos).GetLengthSq();
			if (distance < 0)
			{
				distance = tmp;
				a[0] = i;
				a[1] = j;
			}
			else if (distance > tmp)
			{
				distance = tmp;
				a[0] = i;
				a[1] = j;
			}
		}
	}
}
void Game::UpdateModel(float dt)
{
	//bool *pBoll;
	//pBoll = &(bricks[0][0].isDestroyed);
	//ball.ChangeOtherBool(pBoll);
	//if (bricks[0][0].isDestroyed)
	//{
	//	gfx.PutPixel(20, 400, 255, 255, 255);
	//}
	ball.CheckCollWalls(walls);
	ball.Update(dt);
	CheckBricks();
	
}

void Game::ComposeFrame()
{
	
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < nRow; j++)
		{
			if (!bricks[i][j].isDestroyed)
			{
				bricks[i][j].DrawBrick(gfx);
			}
		}
	}
	ball.Draw(gfx);
	// some things are just too perfect and pure for
	// this cruel world...
}
