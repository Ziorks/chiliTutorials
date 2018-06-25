#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	gfx.DrawRectDim((loc.x * dimension) + padding + offsetX, (loc.y * dimension) + padding + offsetY, dimension - (padding * 2), dimension - (padding * 2), c);
}

void Board::DrawBorder()
{
	gfx.DrawRectBorder(offsetX - padding, offsetY - padding, (width*dimension) + (padding * 2), (height*dimension) + (padding * 2), borderWidth, borderColor);
}

int Board::GetWidth() const
{
	return width;
}

int Board::GetHeight() const
{
	return height;
}

bool Board::IsInBoard(const Location & loc) const
{
	return loc.x >= 0 && loc.x < width &&
		loc.y >= 0 && loc.y < height;
}
