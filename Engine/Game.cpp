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
		if (!inhibitUp)
		{
			vy -= 1;
			inhibitUp = true;
		}
	}
	else
	{
		inhibitUp = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (!inhibitLeft)
		{
			vx -= 1;
			inhibitLeft = true;
		}
	}
	else
	{
		inhibitLeft = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (!inhibitDown)
		{
			vy += 1;
			inhibitDown = true;
		}
	}
	else
	{
		inhibitDown = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (!inhibitRight)
		{
			vx += 1;
			inhibitRight = true;
		}
	}
	else
	{
		inhibitRight = false;
	}
   
	x += vx;
	y += vy;

	if (x > gfx.ScreenWidth - 6)
	{
		x = gfx.ScreenWidth - 6;
		vx = 0;
	}
	if (x < 5)
	{
		x = 5;
		vx = 0;
	}
	if (y > gfx.ScreenHeight - 6)
	{
		y = gfx.ScreenHeight - 6;
		vy = 0;
	}
	if (y < 5)
	{
		y = 5;
		vy = 0;
	}

	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		r = 150;
		g = 50;
		b = 25;
	}
	else
	{
		r = 0;
		g = 200;
		b = 100;
	}

	if (x < boxX + 5 && x > boxX - 5 &&
		y < boxY + 5 && y > boxY - 5)
	{
		r = 255;
		g = 255;
		b = 255;
	}	

	shapeIsChanged = wnd.kbd.KeyIsPressed(VK_SHIFT);
}

void Game::ComposeFrame()
{
	if (!shapeIsChanged)
	{
		gfx.PutPixel(x - 5, y, r, g, b);
		gfx.PutPixel(x - 4, y, r, g, b);
		gfx.PutPixel(x - 3, y, r, g, b);
		gfx.PutPixel(x + 3, y, r, g, b);
		gfx.PutPixel(x + 4, y, r, g, b);
		gfx.PutPixel(x + 5, y, r, g, b);
		gfx.PutPixel(x, y - 5, r, g, b);
		gfx.PutPixel(x, y - 4, r, g, b);
		gfx.PutPixel(x, y - 3, r, g, b);
		gfx.PutPixel(x, y + 3, r, g, b);
		gfx.PutPixel(x, y + 4, r, g, b);
		gfx.PutPixel(x, y + 5, r, g, b);
	}
	else
	{
		gfx.PutPixel(x - 5, y + 5, r, g, b);
		gfx.PutPixel(x - 4, y + 4, r, g, b);
		gfx.PutPixel(x - 3, y + 3, r, g, b);
		gfx.PutPixel(x + 3, y - 3, r, g, b);
		gfx.PutPixel(x + 4, y - 4, r, g, b);
		gfx.PutPixel(x + 5, y - 5, r, g, b);
		gfx.PutPixel(x - 5, y - 5, r, g, b);
		gfx.PutPixel(x - 4, y - 4, r, g, b);
		gfx.PutPixel(x - 3, y - 3, r, g, b);
		gfx.PutPixel(x + 3, y + 3, r, g, b);
		gfx.PutPixel(x + 4, y + 4, r, g, b);
		gfx.PutPixel(x + 5, y + 5, r, g, b);
	}

	gfx.PutPixel(boxX - 5, boxY + 5, boxR, boxG, boxB);
	gfx.PutPixel(boxX - 5, boxY + 4, boxR, boxG, boxB);
	gfx.PutPixel(boxX - 5, boxY + 3, boxR, boxG, boxB);
	gfx.PutPixel(boxX + 5, boxY - 3, boxR, boxG, boxB);
	gfx.PutPixel(boxX + 5, boxY - 4, boxR, boxG, boxB);
	gfx.PutPixel(boxX + 5, boxY - 5, boxR, boxG, boxB);
	gfx.PutPixel(boxX - 5, boxY - 5, boxR, boxG, boxB);
	gfx.PutPixel(boxX - 5, boxY - 4, boxR, boxG, boxB);
	gfx.PutPixel(boxX - 5, boxY - 3, boxR, boxG, boxB);
	gfx.PutPixel(boxX + 5, boxY + 3, boxR, boxG, boxB);
	gfx.PutPixel(boxX + 5, boxY + 4, boxR, boxG, boxB);
	gfx.PutPixel(boxX + 5, boxY + 5, boxR, boxG, boxB);
	gfx.PutPixel(boxX - 4, boxY + 5, boxR, boxG, boxB);
	gfx.PutPixel(boxX - 3, boxY + 5, boxR, boxG, boxB);
	gfx.PutPixel(boxX + 4, boxY - 5, boxR, boxG, boxB);
	gfx.PutPixel(boxX + 3, boxY - 5, boxR, boxG, boxB);
	gfx.PutPixel(boxX - 4, boxY - 5, boxR, boxG, boxB);
	gfx.PutPixel(boxX - 3, boxY - 5, boxR, boxG, boxB);
	gfx.PutPixel(boxX + 4, boxY + 5, boxR, boxG, boxB);
	gfx.PutPixel(boxX + 3, boxY + 5, boxR, boxG, boxB);
}
