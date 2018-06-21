#pragma once
#include "Graphics.h"
#include "Dude.h"

class Poo
{
public:
	void Init(int in_x, int in_y, int in_vx, int in_vy);
	void Update();
	bool CollisionTest(const Dude& dude)const;
	void Draw(Graphics& gfx) const;
private:
	int x;
	int y;
	int vx = 1;
	int vy = 1;
	static constexpr int width = 24;
	static constexpr int height = 24;
	bool initialized = false;
};
