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
}

void Game::ComposeFrame()
{
	int r = 0;
	int b = 200;
	int g = 100;

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y -= 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x -= 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y += 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x += 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		r = 150;
		b = 50;
		g = 25;
	}

	if (!wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		gfx.PutPixel(x - 5, y, r, b, g);
		gfx.PutPixel(x - 4, y, r, b, g);
		gfx.PutPixel(x - 3, y, r, b, g);
		gfx.PutPixel(x + 3, y, r, b, g);
		gfx.PutPixel(x + 4, y, r, b, g);
		gfx.PutPixel(x + 5, y, r, b, g);
		gfx.PutPixel(x, y - 5, r, b, g);
		gfx.PutPixel(x, y - 4, r, b, g);
		gfx.PutPixel(x, y - 3, r, b, g);
		gfx.PutPixel(x, y + 3, r, b, g);
		gfx.PutPixel(x, y + 4, r, b, g);
		gfx.PutPixel(x, y + 5, r, b, g);
	}
	else
	{
		gfx.PutPixel(x - 5, y + 5, r, b, g);
		gfx.PutPixel(x - 4, y + 4, r, b, g);
		gfx.PutPixel(x - 3, y + 3, r, b, g);
		gfx.PutPixel(x + 3, y - 3, r, b, g);
		gfx.PutPixel(x + 4, y - 4, r, b, g);
		gfx.PutPixel(x + 5, y - 5 , r, b, g);
		gfx.PutPixel(x - 5, y - 5, r, b, g);
		gfx.PutPixel(x - 4, y - 4, r, b, g);
		gfx.PutPixel(x - 3, y - 3, r, b, g);
		gfx.PutPixel(x + 3, y + 3, r, b, g);
		gfx.PutPixel(x + 4, y + 4, r, b, g);
		gfx.PutPixel(x + 5, y + 5, r, b, g);
	}
}
