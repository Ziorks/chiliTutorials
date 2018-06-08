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
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		mobile_y -= 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		mobile_x -= 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		mobile_y += 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		mobile_x += 1;
	}
   

	if (mobile_x > gfx.ScreenWidth - 6)
	{
		mobile_x = gfx.ScreenWidth - 6;
	}
	if (mobile_x < 5)
	{
		mobile_x = 5;
	}
	if (mobile_y > gfx.ScreenHeight - 6)
	{
		mobile_y = gfx.ScreenHeight - 6;
	}
	if (mobile_y < 5)
	{
		mobile_y = 5;
	}	

	colliding = 
		OverlapTest(mobile_x, mobile_y, fixed_x0, fixed_y0) ||
		OverlapTest(mobile_x, mobile_y, fixed_x1, fixed_y1) ||
		OverlapTest(mobile_x, mobile_y, fixed_x2, fixed_y2) ||
		OverlapTest(mobile_x, mobile_y, fixed_x3, fixed_y3);
}

void Game::ComposeFrame()
{
	DrawBox(fixed_x0, fixed_y0, 255, 255, 255);
	DrawBox(fixed_x1, fixed_y1, 255, 255, 255);
	DrawBox(fixed_x2, fixed_y2, 255, 255, 255);
	DrawBox(fixed_x3, fixed_y3, 255, 255, 255);

	if (colliding)
	{
		DrawBox(mobile_x, mobile_y, 255, 0, 0);
	}
	else
	{
		DrawBox(mobile_x, mobile_y, 0, 255, 100);
	}
}

void Game::DrawBox(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x - 5, y + 5, r, g, b);
	gfx.PutPixel(x - 5, y + 4, r, g, b);
	gfx.PutPixel(x - 5, y + 3, r, g, b);
	gfx.PutPixel(x + 5, y - 3, r, g, b);
	gfx.PutPixel(x + 5, y - 4, r, g, b);
	gfx.PutPixel(x + 5, y - 5, r, g, b);
	gfx.PutPixel(x - 5, y - 5, r, g, b);
	gfx.PutPixel(x - 5, y - 4, r, g, b);
	gfx.PutPixel(x - 5, y - 3, r, g, b);
	gfx.PutPixel(x + 5, y + 3, r, g, b);
	gfx.PutPixel(x + 5, y + 4, r, g, b);
	gfx.PutPixel(x + 5, y + 5, r, g, b);
	gfx.PutPixel(x - 4, y + 5, r, g, b);
	gfx.PutPixel(x - 3, y + 5, r, g, b);
	gfx.PutPixel(x + 4, y - 5, r, g, b);
	gfx.PutPixel(x + 3, y - 5, r, g, b);
	gfx.PutPixel(x - 4, y - 5, r, g, b);
	gfx.PutPixel(x - 3, y - 5, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);
}

bool Game::OverlapTest(int x0, int y0, int x1, int y1)
{
	const int box0_bottom = y0 + 5;
	const int box0_top = y0 - 5;
	const int box0_left = x0 - 5;
	const int box0_right = x0 + 5;
	const int box1_bottom = y1 + 5;
	const int box1_top = y1 - 5;
	const int box1_left = x1 - 5;
	const int box1_right = x1 + 5;

	return
		box0_left <= box1_right &&
		box0_right >= box1_left &&
		box0_top <= box1_bottom &&
		box0_bottom >= box1_top;
}

//homework:
//ezpz mode: create function to keep box within window
//hard mode: same thing but can't use x_mobile or y_mobile (ie can't use member variables directly)