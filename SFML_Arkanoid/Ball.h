#pragma once
#include <SFML\Graphics.hpp>

struct Ball
{
	const float missleRadius{ 10.f };
	const float missleSpeed{ 8.f };
	
	Ball(double, double);
	void Update();
	float x();
	float y();
	float left();
	float right();
	float top();
	float bottom();
	sf::CircleShape mMissle;	
	sf::Vector2f	speed{ -missleSpeed, -missleSpeed };
};

