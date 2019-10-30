#include <sstream>
#include <cstdlib>
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Menu.h"
#include "TwoPlayers.h"
#include "TextBox.h"
#include "Button.h"

// This is where our game starts from
int main()
{
	int WIDTH = 1000;
	int HEIGHT = 800;
	
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");

	Texture texture;
	texture.loadFromFile("39607.jpg");
	Sprite sprite(texture);

	Font font;
	font.loadFromFile("simson.ttf");
	Text title("PING PONG GAME", font);
	title.setPosition(120, 150);
	title.setCharacterSize(100);
	title.setFillColor(sf::Color(26, 58, 245, 255));
	Menu menu;
	int choose = 0;

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
						choose = 1;
						window.close();
						break;
					case 1:
						choose = 2;
						window.close();
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
			window.draw(title);
			window.display();
		
		

	}
	if (choose == 1)
	{
		RectangleShape box1;
		box1.setSize(Vector2f(400, 50));
		box1.setPosition(Vector2f(300, 180));

		RectangleShape box2;
		box2.setSize(Vector2f(400, 50));
		box2.setPosition(Vector2f(300, 380));

		Text text1;
		text1.setString("Name of player 1: ");
		text1.setFont(font);
		text1.setPosition(Vector2f(100, 80));
		text1.setCharacterSize(40);

		Text text2;
		text2.setString("Name of player 2: ");
		text2.setFont(font);
		text2.setPosition(Vector2f(100, 280));
		text2.setCharacterSize(40);

		Font font;
		font.loadFromFile("Cucho Bold.otf");

		TextBox textbox1;
		textbox1.setTextBox(35, Color::Blue, true);
		textbox1.setFont(font);
		textbox1.setLimit(true, 20);
		textbox1.setPosition(Vector2f(310, 185));

		TextBox textbox2;
		textbox2.setTextBox(35, Color::Blue, true);
		textbox2.setFont(font);
		textbox2.setLimit(true, 20);
		textbox2.setPosition(Vector2f(310, 385));

		Button button;
		button.setButton("PLAY NOW", { 200,80 }, 30, Color::Green, Color::Black);
		button.setFont(font);
		button.setPosition({ 400, 550 });

		RenderWindow window1(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");
		while (window1.isOpen())
		{

			Event event;
			while (window1.pollEvent(event))
			{
				switch (event.type)
				{
				case Event::Closed:
					window1.close();
				case Event::TextEntered:
						if (textbox1.getLimit() != 0)
						{
							textbox1.typedOn(event);
						}
						else
						{
							textbox2.typedOn(event);
						}
				case Event::MouseMoved:
						if (button.isMouseOver(window1))
						{
							button.setBackColor(Color::Blue);
						}
						else
						{
							button.setBackColor(Color::Green);
						}
						break;
				case Event::MouseButtonPressed:
						if (button.isMouseOver(window1))
						{
							cout << "Hello " << textbox1.getText() << "\n";
							cout << "Hello " << textbox2.getText() << "\n";
						}
					
				}
			}
			window1.clear();
			window1.draw(sprite);

			window1.draw(text1);
			window1.draw(text2);

			window1.draw(box1);
			window1.draw(box2);

			textbox1.draw(window1);
			textbox2.draw(window1);
			button.draw(window1);
			window1.display();
		}
	}
	else if (choose == 2)
	{
		RectangleShape box;
		box.setSize(Vector2f(400, 50));
		box.setPosition(Vector2f(300, 380));

		Text text;
		text.setString("Name of player: ");
		text.setFont(font);
		text.setPosition(Vector2f(350, 210));
		text.setCharacterSize(40);

		TextBox textbox;
		Font font;
		font.loadFromFile("Cucho Bold.otf");
		textbox.setTextBox(35, Color::Blue, true);
		textbox.setFont(font);
		textbox.setLimit(true, 20);
		textbox.setPosition(Vector2f(310, 385));

		Button button;
		button.setButton("PLAY NOW", { 200,80 }, 30, Color::Green, Color::Black);
		button.setFont(font);
		button.setPosition({ 400, 550 });

		RenderWindow window2(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");
		while (window2.isOpen())
		{

			Event event;
			while (window2.pollEvent(event))
			{
				switch (event.type)
				{
				case Event::Closed:
					window2.close();
				case Event::TextEntered:
					if (textbox.getLimit() != 0)
					{
						textbox.typedOn(event);
					}
				case Event::MouseMoved:
					if (button.isMouseOver(window2))
					{
						button.setBackColor(Color::Blue);
					}
					else
					{
						button.setBackColor(Color::Green);
					}
					break;
				case Event::MouseButtonPressed:
					if (button.isMouseOver(window2))
					{
						cout << "Hello " << textbox.getText() << "\n";
					}
				}
			}
			window2.clear();
			window2.draw(sprite);

			window2.draw(text);

			window2.draw(box);

			textbox.draw(window2);

			button.draw(window2);
			window2.display();
		}
	}
	return 0;
}