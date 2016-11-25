#pragma once
#include <SFML\Graphics.hpp>
struct Player
{
	const float playerSpeed{ 6.f };
	const float playerWidth{ 90.f };
	const float playerHeigth{ 25.f };

	Player(float,float);
	void Update();
	float x();
	float y();
	float left();
	float right();
	float top();
	float bottom();

	sf::RectangleShape player_;
	sf::Vector2f speed_;
};

