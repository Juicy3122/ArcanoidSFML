#include "Game.h"
#include <vector>
#include <algorithm>

Game::Game() 
: mWindow(sf::VideoMode(800, 600), "Arcanoid")
, mMissle{ 400, 300 }
, mPlayer{ 400, 550 }
{
	mWindow.setVerticalSyncEnabled(true);
	GenerateBricks(Brick::countBricksX, Brick::countBricksY);
}

void Game::Run()
{
	while (mWindow.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) break;
		ProcessEvents();
		Update();
		testCollisions();
		Render();
	}
}

void Game::ProcessEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{			
		case sf::Event::Closed:
			mWindow.close();
			break;
		default:
			break;
		}
		
	}
	
}

template<class T1, class T2> bool Game::isIntersecting(T1& mA, T2& mB)
{
	return mA.right() > mB.left() && mA.left() <= mB.right() && mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

void Game::GenerateBricks(int countX, int countY)
{
	for (int i = 0; i < countX; i++)
	{
		for (int y = 0; y < countY; y++)
		{
			mBricks.emplace_back((i + 1)*(brickWidth + 3) + 22,
								(y + 1)*(brickHeight + 3));
		}
	}
}

void Game::testCollisions()
{
	if (!isIntersecting(mPlayer, mMissle)) return;

	mMissle.speed.y = -mMissle.missleSpeed;
	if (mMissle.x() < mPlayer.x())
	{
		mMissle.speed.x = -mMissle.missleSpeed;
	}
	else
	{
		mMissle.speed.x = mMissle.missleSpeed;
	}
}

void Game::testCollisions(Brick& brick)
{
	if (!isIntersecting(brick, mMissle)) return;
	brick.destroyed = true;

	float overlapLeft{ brick.right() - brick.left() };
	float overlapRight{ mMissle.right() - mMissle.left() };
	float overlapTop{ brick.bottom() - brick.top() };
	float overlapBottom{ brick.bottom() - brick.top() };

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

	if (abs(minOverlapX) < abs(minOverlapY))
		mMissle.speed.x = ballFromLeft ? -mMissle.missleSpeed : mMissle.missleSpeed;
	else
		mMissle.speed.y = ballFromTop ? -mMissle.missleSpeed : mMissle.missleSpeed;
}
void Game::Update()
{
	for (auto& brick : mBricks)
	{
		testCollisions(brick);
	}

	mBricks.erase(std::remove_if(begin(mBricks), end(mBricks),
					[](const Brick& mBrick)
					{
						return mBrick.destroyed;
					}),
				end(mBricks));
	

	mMissle.Update();
	mPlayer.Update();
}

void Game::Render()
{
	mWindow.clear();
	for (auto & brick : mBricks)
	{
		mWindow.draw(brick.shape);
	}
	mWindow.draw(mMissle.mMissle);
	mWindow.draw(mPlayer.shape);
	mWindow.display();
}

Game::~Game()
{
}
