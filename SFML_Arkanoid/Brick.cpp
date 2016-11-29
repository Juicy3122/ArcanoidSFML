#include "Brick.h"
#include "Game.h"


Brick::Brick(float x, float y)
{
	shape.setPosition(x, y);
	shape.setSize({ brickWidth, brickHeight });
	shape.setFillColor(sf::Color::Yellow);
	shape.setOrigin(brickWidth / 2.f, brickHeight / 2.f);
}

