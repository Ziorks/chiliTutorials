#pragma once

#include "Graphics.h"
#include "Location.h"

class Board {
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	void DrawBorder();
	int GetWidth()const;
	int GetHeight()const;
	bool IsInBoard(const Location& loc)const;
private:
	static constexpr int offsetX = 100;
	static constexpr int offsetY = 100;
	static constexpr int borderWidth = 3;
	static constexpr int dimension = 20;
	static constexpr int width = 30;
	static constexpr int height = 20;
	static constexpr int padding = 2;
	static constexpr Color borderColor = Colors::Cyan;
	Graphics& gfx;
};