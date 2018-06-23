#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell(Location& loc, Color c)
{
	gfx.DrawRectDim((loc.x * dimension) + padding, (loc.y * dimension) + padding, dimension - (padding * 2), dimension - (padding * 2), c);
}

int Board::GetWidth() const
{
	return width;
}

int Board::GetHeight() const
{
	return height;
}
