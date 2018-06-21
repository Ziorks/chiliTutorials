#include "ScoreBar.h"

ScoreBar::ScoreBar(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}

void ScoreBar::Draw(Graphics & gfx) const
{
	gfx.DrawRectDim(x, y, score * widthScale, height, c);
}

void ScoreBar::IncreaseScore()
{
	score++;
}
