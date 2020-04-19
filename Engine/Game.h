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
#include "Ball.h"
#include "FrameTimer.h"
#include "Brick.h"
#include "Pad.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();

	void InitBriks();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void DrawBriks(Graphics& gfx);
	/********************************/
private:
	static constexpr int numberOfBricks = 19 ;
	static constexpr int numberOfLayers = 5;
	MainWindow& wnd;
	Graphics gfx;
	Ball ball;
	FrameTimer ft;
	RectF walls;
	Pad pad;
	Brick brick[numberOfBricks][numberOfLayers];
	Vec2 offset = Vec2(20.0f, 20.0f);
	Vec2 sizeOfBrik=Vec2(40.0f, 16.0f);
	Vec2 posOfBriks[numberOfBricks][numberOfLayers];
//	RectF briks[4*numberOfBricks];
	/********************************/
	/*  User Variables              */
	/********************************/
};