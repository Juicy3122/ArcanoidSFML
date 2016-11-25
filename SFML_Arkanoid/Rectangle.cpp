#include "Rectangle.h"


Rectangle::Rectangle()
{
}

float Rectangle::x()
{
	return shape.getPosition().x;
}
float Rectangle::y()
{
	return shape.getPosition().y;
}
float Rectangle::left()
{
	return x() - shape.getSize().x / 2.f;
}
float Rectangle::right()
{
	return x() + shape.getSize().x / 2.f;
}
float Rectangle::top()
{
	return y() - shape.getSize().y / 2.f;
}
float Rectangle::bottom()
{
	return y() + shape.getSize().y / 2.f;
}
