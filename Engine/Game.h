/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Brick.h"
#include "Vec2.h"
#include "Ball.h"
#include "FrameTimer.h"
#include "Pad.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel(float dt);
	/********************************/
	/*  User Functions              */
	/********************************/

	void InitBriks();
	void InitMap();
	void CheckBricks();
	int MapGetPosX(Vec2 pos);
	int Game::MapGetPosY(Vec2 pos);
	void GetDistance(int i, int j);
	//bool CheckAnglesofBrick(Brick b, Ball ball);
	//int ToTheRight(RectF r1, RectF r2);
	
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	const static int row = 19;
	const static int nRow = 5;
	Brick bricks[row][nRow];
	Vec2 sizeOfBrik=Vec2(40, 20);
	Vec2 offset = Vec2(20, 20);
	Vec2 map[40][30];
	FrameTimer ft;
	Ball ball;
	RectF walls;
	float distance;
	int a[2];
	Pad pad;
};