#include "Poo.h"
#include "Graphics.h"
#include "Dude.h"

void Poo::Update()
{
	x += vx;
	y += vy;

	if (x < 0)
	{
		x = 0;
		vx = -vx;
	}
	else if (x + width >= Graphics::ScreenWidth)
	{
		x = (Graphics::ScreenWidth - 1) - width;
		vx = -vx;
	}

	if (y < 0)
	{
		y = 0;
		vy = -vy;
	}
	else if (y + height >= Graphics::ScreenHeight)
	{
		y = (Graphics::ScreenHeight - 1) - height;
		vy = -vy;
	}
}

void Poo::ProcessConsumption(int dudex, int dudey, int dudewidth, int dudeheight)
{
	int bottomPoo = y + height;
	int rightPoo = x + width;
	int bottomDude = dudey + dudeheight;
	int rightDude = dudex + dudewidth;

	if (
		x <= rightDude &&
		rightPoo >= x &&
		y <= bottomDude &&
		bottomPoo >= y)
	{
		isEaten = true;
	}
}
