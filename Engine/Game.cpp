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
	if (wnd.kbd.KeyIsPressed('D'))
	{
		boxX++;
	}
	if (wnd.kbd.KeyIsPressed('A'))
	{
		boxX--;
	}
	if (wnd.kbd.KeyIsPressed('W'))
	{
		boxY--;
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		boxY++;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		height--;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		height++;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		width--;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		width++;
	}
}

void Game::ComposeFrame()
{
	for (int x = boxX; x < boxX + width; x++)
	{
		for (int y = boxY; y < boxY + height; y++)
		{
			gfx.PutPixel(x, y, 255, 255, 255);
		}
	}
}
