#pragma once
#include <SFML\Graphics.hpp>
#include "Ball.h"
#include "Player.h"
class Game
{

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

