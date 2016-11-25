#include "Player.h"


Player::Player(float x, float y)
{
	player_.setPosition(x, y);
	player_.setSize({playerWidth,playerHeigth});
	player_.setFillColor(sf::Color::Cyan);
	player_.setOrigin(playerWidth / 2.f, playerHeigth / 2.f);
}
void Player::Update()
{
	player_.move(speed_);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && left() > 0)
		speed_.x = -playerSpeed;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && right() < 800)
		speed_.x = playerSpeed;
	else
		speed_.x = 0;
}

float Player::x()
{
	return player_.getPosition().x;
}
float Player::y()
{
	return player_.getPosition().y;
}
float Player::left()
{
	return x() - player_.getSize().x / 2.f;
}
float Player::right()
{
	return x() + player_.getSize().x /2.f;
}
float Player::top()
{
	return y() - player_.getSize().y / 2.f;
}
float Player::bottom()
{
	return y() + player_.getSize().y /2.f;
}