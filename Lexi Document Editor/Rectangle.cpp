#include "Rectangle.h"

Rectangle::Rectangle(sf::Vector2f size)
{
	mRect.setFillColor(sf::Color::Black);
	mRect.setSize(size);
}

void Rectangle::Draw(Window * window)
{
	window->draw(mRect);
}

void Rectangle::Bounds(Rect & rect)
{
	rect = this->mRect.getLocalBounds();
}

void Rectangle::setPosition(Point point)
{
	this->mRect.setPosition(point);
}

bool Rectangle::Intersects(const Point & p)
{
	return this->mRect.getLocalBounds().contains(p);
}

void Rectangle::Insert(Glyph * glyph, int position)
{
}

void Rectangle::Remove(Glyph * glyph)
{
}

Glyph * Rectangle::Child(int cid)
{
	return nullptr;
}

Glyph * Rectangle::Parent()
{
	return nullptr;
}
