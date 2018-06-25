#pragma once

#include "Board.h"

class Snake
{
public:
	Snake(const Location& in_loc);
	void Draw(Board& brd)const;
	void Grow();
	void MoveBy(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc)const;
	bool IsInTile(const Location& target)const;
	bool IsInTileExceptEnd(const Location& target)const;

private:
	class Segment
	{
	public:
		void InitHead(const Location& in_loc);
		void InitBody();
		void Draw(Board& brd)const;
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		const Location& GetLocation()const;
	private:
		Location loc;
		Color c;
	};

private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
};