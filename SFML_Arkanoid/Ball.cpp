#include "Ball.h"

Ball::Ball(double x, double y)
{
	mMissle.setPosition(x, y);
	mMissle.setRadius(missleRadius);
	mMissle.setFillColor(sf::Color::Green);
	mMissle.setOrigin(missleRadius, missleRadius);
}

void Ball::Update()
{
	mMissle.move(speed);
	if (left() < 0)
		speed.x = missleSpeed;
	else if (right() > 800)
		speed.x = -missleSpeed;
	if (top() < 0)
		speed.y = missleSpeed;
	else if (bottom() > 600) 
		speed.y = -missleSpeed;
}

float Ball::x()
{
	return mMissle.getPosition().x;
}
float Ball::y()
{
	return mMissle.getPosition().y;
}
float Ball::left()
{
	return x() - mMissle.getRadius();
}
float Ball::right()
{
	return x() + mMissle.getRadius();
}
float Ball::top()
{
	return y() - mMissle.getRadius();
}
float Ball::bottom()
{
	return y() + mMissle.getRadius();
}