#include <sstream>
#include <cstdlib>
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "EndMenu.h"

// This is where our game starts from
int main()
{
	int WIDTH = 1024;
	int HEIGHT = 768;

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");

	//tao background cho man hinh menu
	Texture texture;
	texture.loadFromFile("39607.jpg");
	Sprite sprite(texture);

	//In tieu de menu
	Font font;
	font.loadFromFile("Facon.ttf");
	Text title("GAME OVER", font);
	title.setPosition(200, 150);
	title.setCharacterSize(100);
	title.setFillColor(Color(26, 58, 175, 255));
	
	EndMenu endMenu(WIDTH, HEIGHT);

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
					endMenu.moveUp();
					break;
				case Keyboard::Down:
					endMenu.moveDown();
					break;
				case Keyboard::Return:
					switch (endMenu.getChoose())
					{
					case 0:
						cout << "Play again button" << endl;
						break;
					case 1:
						cout << "Show highscores button" << endl;
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
		endMenu.draw(window);
		window.draw(title);
		window.display();

	}

	return 0;
}