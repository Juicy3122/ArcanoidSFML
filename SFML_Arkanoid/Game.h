#pragma once
#include <SFML\Graphics.hpp>
#include "Ball.h"
#include "Player.h"
class Game
{
private:
	const float missleRadius{ 10.f };
	const float missleSpeed{ 8.f };
public:
	Game();
	void Run();
	~Game();
private:
	void ProcessEvents();
	void Update();
	void Render();
	bool isIntersecting(Player&, Ball&);
	void testCollisions();

	sf::RenderWindow	mWindow;
	Ball				mMissle;
	Player				mPlayer;
};

