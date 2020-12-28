#pragma once
#include "Glyph.h"
#include "SFML/Graphics/RectangleShape.hpp"

class Rectangle : public Glyph
{
public:
	Rectangle(sf::Vector2f size = sf::Vector2f(0, 0));
	// Inherited via Glyph
	virtual void Draw(Window * window) override;
	virtual void Bounds(Rect & rect) override;
	virtual void setPosition(Point point) override;
	virtual bool Intersects(const Point & p) override;
private:
	sf::RectangleShape mRect;
	virtual void Insert(Glyph * glyph, int position) override;
	virtual void Remove(Glyph * glyph) override;
	virtual Glyph * Child(int cid) override;
	virtual Glyph * Parent() override;
};

