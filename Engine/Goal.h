#pragma once

#include"Graphics.h"
#include "Colors.h"
#include "Dude.h"

class Goal {
public:
	Goal(int in_x, int in_y);
	void Draw(Graphics& gfx)const;
	void UpdateColor();
	void Respawn(int in_x, int in_y);
	bool CollisionTest(const Dude& dude)const;
private:
	int x;
	int y;
	Color c = {127,0,0};
	static constexpr int dimension = 15;
	bool colorIncreasing = true;
};