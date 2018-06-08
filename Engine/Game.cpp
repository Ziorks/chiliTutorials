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

	const int mobile_bottom = mobile_y + 5;
	const int mobile_top = mobile_y - 5;
	const int mobile_left = mobile_x - 5;
	const int mobile_right = mobile_x + 5;

	if (mobile_left < fixed_right && 
		mobile_right > fixed_left &&
		mobile_top < fixed_bottom && 
		mobile_bottom > fixed_top)
	{
		mobile_r = 255;
		mobile_g = 0;
		mobile_b = 0;
	}
	else
	{
		mobile_r = 0;
		mobile_g = 255;
		mobile_b = 100;
	}
}

void Game::ComposeFrame()
{
	gfx.PutPixel(mobile_x - 5, mobile_y + 5, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x - 5, mobile_y + 4, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x - 5, mobile_y + 3, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x + 5, mobile_y - 3, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x + 5, mobile_y - 4, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x + 5, mobile_y - 5, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x - 5, mobile_y - 5, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x - 5, mobile_y - 4, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x - 5, mobile_y - 3, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x + 5, mobile_y + 3, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x + 5, mobile_y + 4, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x + 5, mobile_y + 5, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x - 4, mobile_y + 5, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x - 3, mobile_y + 5, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x + 4, mobile_y - 5, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x + 3, mobile_y - 5, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x - 4, mobile_y - 5, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x - 3, mobile_y - 5, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x + 4, mobile_y + 5, mobile_r, mobile_g, mobile_b);
	gfx.PutPixel(mobile_x + 3, mobile_y + 5, mobile_r, mobile_g, mobile_b);


	gfx.PutPixel(fixed_x - 5, fixed_y + 5, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x - 5, fixed_y + 4, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x - 5, fixed_y + 3, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x + 5, fixed_y - 3, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x + 5, fixed_y - 4, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x + 5, fixed_y - 5, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x - 5, fixed_y - 5, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x - 5, fixed_y - 4, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x - 5, fixed_y - 3, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x + 5, fixed_y + 3, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x + 5, fixed_y + 4, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x + 5, fixed_y + 5, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x - 4, fixed_y + 5, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x - 3, fixed_y + 5, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x + 4, fixed_y - 5, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x + 3, fixed_y - 5, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x - 4, fixed_y - 5, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x - 3, fixed_y - 5, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x + 4, fixed_y + 5, fixed_r, fixed_g, fixed_b);
	gfx.PutPixel(fixed_x + 3, fixed_y + 5, fixed_r, fixed_g, fixed_b);
}
