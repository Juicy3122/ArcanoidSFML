#pragma once
#include <SFML\Graphics.hpp>

struct Rectangle
{
	sf::RectangleShape shape;
	Rectangle();	

	float x();
	float y();
	float left();
	float right();
	float top();
	float bottom();
};

