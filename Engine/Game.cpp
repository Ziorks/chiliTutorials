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
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( gfx ),
	rng(std::random_device()()),
	snek({15,10}),
	goal(rng,brd,snek)
{
	std::uniform_int_distribution<int> directionDist(0, 3);
	snekDirection = directionDist(rng);
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
	if (!gameIsStarted)
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			gameIsStarted = true;
		}
	}
	if (gameIsStarted && !gameIsOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			snekDirection = 2;
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			snekDirection = 3;
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			snekDirection = 0;
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			snekDirection = 1;
		}
		moveCounter++;
		if (moveCounter >= movePeriod)
		{
			moveCounter = 0;
			const Location next = snek.GetNextHeadLocation(snekDeltaLoc[snekDirection]);
			if (!brd.IsInBoard(next)||
				snek.IsInTileExceptEnd(next))
			{
				gameIsOver = true;
			}
			else
			{
				if (goal.GetLocation() == next)
				{
					speedCounter++;
					if (speedCounter >= speedPeriod &&
						movePeriod > 10)
					{
						movePeriod -= 3;
						speedCounter = 0;
					}
					snek.Grow();
					snek.MoveBy(snekDeltaLoc[snekDirection]);
					goal.Respawn(rng, brd, snek);
				}
				else
				{
					snek.MoveBy(snekDeltaLoc[snekDirection]);
				}
			}
		}
	}
}

void Game::ComposeFrame()
{
	if (!gameIsStarted)
	{
		SpriteCodex::DrawTitle(300,200,gfx);
	}
	else
	{
		goal.Draw(brd);
		snek.Draw(brd);
		brd.DrawBorder();
		if (gameIsOver)
		{
			SpriteCodex::DrawGameOver(350, 275, gfx);
		}
	}
}
