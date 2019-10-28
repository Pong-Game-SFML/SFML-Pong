#include <sstream>
#include <cstdlib>
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Menu.h"

// This is where our game starts from
int main()
{
	int windowW = 1024;
	int windowHeight = 768;
	
	RenderWindow window(VideoMode(windowW, windowHeight), "Pong");

	Texture texture;
	texture.loadFromFile("39607.jpg");
	Sprite sprite(texture);
	Font font;
	font.loadFromFile("simson.ttf");

	// Set the font to our message
	Text hud("PING PONG GAME", font);

	hud.setPosition(180, 200);
	//hud.setFont(font);
	hud.setCharacterSize(90);
	hud.setFillColor(sf::Color(26, 58, 245, 255));
	Menu menu(windowW, windowHeight);

	Event event;
	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Up:
					menu.moveUp();
					break;
				case Keyboard::Down:
					menu.moveDown();
					break;
				case Keyboard::Return:
					switch (menu.getChoose())
					{
					case 0:
						cout << "Play buttons" << endl;
						break;
					case 1:
						cout << "Options buttons" << endl;
						break;
					case 2:
						window.close();
						break;
					}
				}
				break;
			}
			
		}
		window.draw(sprite);
		menu.draw(window);
		window.draw(hud);
		window.display();

	}

	return 0;
}