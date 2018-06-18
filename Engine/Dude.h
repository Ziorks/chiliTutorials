#pragma once
#include"Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	void Draw(Graphics& gfx)const;
	void Move(const Keyboard& kbd);
	int GetXPos()const;
	int GetYPos()const;
	int GetWidth()const;
	int GetHeight()const;
private:
	int x = 400;
	int y = 300;
	static constexpr int speed = 1;
	static constexpr int width = 20;
	static constexpr int height = 20;
};