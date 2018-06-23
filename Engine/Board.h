#pragma once

#include "Graphics.h"
#include "Location.h"

class Board {
public:
	Board(Graphics& gfx);
	void DrawCell(Location& loc, Color c);
	int GetWidth()const;
	int GetHeight()const;
private:
	static constexpr int dimension = 20;
	static constexpr int width = 40;
	static constexpr int height = 30;
	static constexpr int padding = 2;
	Graphics& gfx;
};