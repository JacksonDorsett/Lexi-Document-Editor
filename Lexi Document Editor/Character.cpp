#include "Character.h"
#include "SFML/System/String.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "FontLoader.h"
Character::Character(char c,Font * font, int size) {
	this->c = c;
	this->txt.setString(sf::String(c));
	this->txt.setCharacterSize(size);
	txt.setFillColor(sf::Color::Black);
	auto origin = txt.getOrigin();
	this->font = font;
	txt.setFont(*font);
	//default font must be loaded properly in FontLoader class
	printf("(%d,%d)", origin.x, origin.y);

}

void Character::Draw(Window * window)
{
	auto r = sf::RectangleShape(sf::Vector2f(10, 10));
	r.setFillColor(sf::Color::Black);
	window->draw(this->txt);
}

void Character::Bounds(Rect & rect)
{
	rect = this->txt.getLocalBounds();
	rect.height = this->txt.getCharacterSize();
}

void Character::setPosition(Point point) {
	this->txt.setPosition(point);

}

bool Character::Intersects(const Point & p)
{
	return false;
}

void Character::setFont(Font *font) {
	this->font = font;
	this->txt.setFont(*font);

}

void Character::Insert(Glyph * glyph, int position)
{
}

void Character::Remove(Glyph * glyph)
{
}

Glyph * Character::Child(int cid)
{
	return nullptr;
}

Glyph * Character::Parent()
{
	return nullptr;
}
