#pragma once
#include <SFML\Graphics.hpp>
#include "Rectangle.h"
struct Player : public Rectangle 
{
	const float playerSpeed{ 6.f };
	const float playerWidth{ 90.f };
	const float playerHeigth{ 25.f };

	Player(float,float);
	void Update();

	sf::Vector2f speed_;
};

