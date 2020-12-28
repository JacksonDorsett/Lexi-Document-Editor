#include <SFML/Window.hpp>
#include "type.h"
#include "Character.h"
#include "Rectangle.h"
#include "Row.h"
#include "Column.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "FontLoader.h"
int main()
{
	
	Font* font = FontLoader::Load_Default_Font();
	
	Character c = Character('A', FontLoader::Load_Font("times.ttf"));

	Rectangle rect(Point(30, 30));
	Column r = Column();
	r.Insert(&c, 0);
	r.Insert(&rect, 1);
	Rect bound;
	c.Bounds(bound);
	std::cout << "rect bounds: " << bound.left << ", " << bound.top << ", " << bound.width << ", " << bound.height << std::endl;
	Window window;
	window.create(sf::VideoMode(800, 600), "My window");
	
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		r.Draw(&window);

		window.display();
	}

	return 0;

}