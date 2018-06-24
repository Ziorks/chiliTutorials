#pragma once

#include "Board.h"
#include "Snake.h"

class Goal
{
public:
	Goal(const Location& in_loc);
	void Respawn(const Location& in_loc, const Snake& snek);
	void Draw(Board& brd)const;
private:
	Location loc;
	static constexpr Color c = Colors::Red;
};