#pragma once
#include <SFML\Graphics.hpp>
#include "Ball.h"
#include "Player.h"
#include "Brick.h"
#include <vector>
#include <algorithm>
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
	void GenerateBricks(int,int);
	template <class T1, class T2> bool isIntersecting(T1&, T2&);
	void testCollisions();
	void testCollisions(Brick&);
	sf::RenderWindow	mWindow;
	Ball				mMissle;
	Player				mPlayer;
	std::vector<Brick>	mBricks;
};

