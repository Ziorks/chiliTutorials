#include "Goal.h"

Goal::Goal(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}

void Goal::Draw(Graphics & gfx)const
{
	gfx.DrawRectDim(x, y, dimension, dimension, c);
}

void Goal::UpdateColor()
{
	if (colorIncreasing)
	{
		if (c.GetR() > 250)
		{
			colorIncreasing = false;
		}
		c = Color( c.GetR() + 2, c.GetG() + 4, c.GetB() + 4 );
	}
	else
	{
		if (c.GetR() < 131)
		{
			colorIncreasing = true;
		}
		c = Color( c.GetR() - 2, c.GetG() - 4, c.GetB() - 4 );
	}
}

void Goal::Respawn(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}

bool Goal::CollisionTest(const Dude & dude) const
{
	int bottomGoal = y + dimension;
	int rightGoal = x + dimension;
	int bottomDude = dude.GetYPos() + dude.GetHeight();
	int rightDude = dude.GetXPos() + dude.GetWidth();

	return
		x <= rightDude &&
		rightGoal >= dude.GetXPos() &&
		y <= bottomDude &&
		bottomGoal >= dude.GetYPos();
}
