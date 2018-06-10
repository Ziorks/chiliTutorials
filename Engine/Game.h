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

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void DrawFace(int x, int y);
	void DrawPoo(int x, int y);
	void DrawTitle(int x, int y);
	void DrawGameOver(int x, int y);
	bool OverlapTest(int x0, int y0, int width0, int height0,
		int x1, int y1, int width1, int height1);
	int ClampScreenX(int x, int width);
	int ClampScreenY(int y, int height);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	int dudeX = 400;
	int dudeY = 300;
	const int dudeWidth = 20;
	const int dudeHeight = 20;
	const int pooWidth = 24;
	const int pooHeight = 24;
	int poo0X;
	int poo0Y;
	int poo0vx = -1;
	int poo0vy = -1;
	bool poo0IsEaten = false;
	int poo1X;
	int poo1Y;
	int poo1vx = 1;
	int poo1vy = -1;
	bool poo1IsEaten = false;
	int poo2X;
	int poo2Y;
	int poo2vx = -1;
	int poo2vy = 1;
	bool poo2IsEaten = false;
	bool gameIsStarted = false;
	/********************************/
};