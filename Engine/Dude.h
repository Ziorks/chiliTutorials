#pragma once
#include"Graphics.h"
#include "MainWindow.h"

class Dude
{
public:
	void Draw(Graphics& gfx)const;
	void Move(const MainWindow& wnd);
	int GetXPos()const;
	int GetYPos()const;
	static constexpr int width = 20;
	static constexpr int height = 20;
private:
	int x = 400;
	int y = 300;
};