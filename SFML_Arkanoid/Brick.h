#pragma once
#include "Rectangle.h"
struct Brick : public Rectangle
{
	static const int countBricksX{ 11 }, countBricksY{ 4 };
	
	
	Brick(float, float);
	void Update();

	bool destroyed{ false };
};

const float brickWidth = 60;
const float brickHeight = 20;