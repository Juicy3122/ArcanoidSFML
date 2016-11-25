#include "Game.h"


Game::Game() 
: mWindow(sf::VideoMode(800, 600), "Arcanoid")
, mMissle{ 400, 300 }
, mPlayer{ 400, 550 }
{
	mWindow.setVerticalSyncEnabled(true);
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

bool Game::isIntersecting(Player& mA, Ball& mB)
{
	return mA.right() > mB.left() && mA.left() <= mB.right() && mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

void Game::testCollisions()
{
	if (!isIntersecting(mPlayer, mMissle)) return;

	mMissle.speed.y = -mMissle.missleSpeed;
	if (mMissle.x() < mPlayer.x())
	{
		mMissle.speed.x = - mMissle.missleSpeed;
	}
	else
	{
		mMissle.speed.x = mMissle.missleSpeed;
	}
}

void Game::Update()
{
	mMissle.Update();
	mPlayer.Update();
}

void Game::Render()
{
	mWindow.clear();
	mWindow.draw(mMissle.mMissle);
	mWindow.draw(mPlayer.shape);
	mWindow.display();
}

Game::~Game()
{
}
