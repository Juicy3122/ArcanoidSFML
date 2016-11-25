#include "Player.h"


Player::Player(float x, float y)
{
	shape.setPosition(x, y);
	shape.setSize({playerWidth,playerHeigth});
	shape.setFillColor(sf::Color::Cyan);
	shape.setOrigin(playerWidth / 2.f, playerHeigth / 2.f);
}
void Player::Update()
{
	shape.move(speed_);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && left() > 0)
		speed_.x = -playerSpeed;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && right() < 800)
		speed_.x = playerSpeed;
	else
		speed_.x = 0;
}

