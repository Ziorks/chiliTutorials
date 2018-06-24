#include "Goal.h"

Goal::Goal(const Location & in_loc)
{
	loc = in_loc;
}

void Goal::Respawn(const Location & in_loc, const Snake & snek)
{
	loc = in_loc;
}

void Goal::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}
