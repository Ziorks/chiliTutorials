#pragma once

#include "Graphics.h"
#include "Colors.h"

class ScoreBar {
public:
	ScoreBar(int in_x, int in_y);
	void Draw(Graphics& gfx)const;
	void IncreaseScore();
private:
	int x;
	int y;
	int score = 0;
	static constexpr int widthScale = 10;
	static constexpr int height = 10;
	Color c = Colors::Blue;
};