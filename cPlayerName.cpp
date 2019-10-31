#include "cPlayerName.h"

int WIDTH = 1000;
int HEIGHT = 800;

void cPlayerName::setTheTextBoxTwoPlayer()
{
	box1.setSize(Vector2f(400, 50));
	box1.setPosition(Vector2f(300, 180));

	box2.setSize(Vector2f(400, 50));
	box2.setPosition(Vector2f(300, 380));

	text1.setString("Name of player 1: ");
	text1.setFont(font);
	text1.setPosition(Vector2f(100, 80));
	text1.setCharacterSize(40);

	text2.setString("Name of player 2: ");
	text2.setFont(font);
	text2.setPosition(Vector2f(100, 280));
	text2.setCharacterSize(40);

	font.loadFromFile("Cucho Bold.otf");

	textbox1.setTextBox(35, Color::Blue, true);
	textbox1.setFont(font);
	textbox1.setLimit(true, 20);
	textbox1.setPosition(Vector2f(310, 185));

	textbox2.setTextBox(35, Color::Blue, true);
	textbox2.setFont(font);
	textbox2.setLimit(true, 15);
	textbox2.setPosition(Vector2f(310, 385));
}

void cPlayerName::setTheButtonPlay()
{
	button.setButton("PLAY NOW", { 200,80 }, 30, Color::Green, Color::Black);
	button.setFont(font);
	button.setPosition({ 400, 550 });
}

vector <string> cPlayerName::fillNameTwoPlayer()
{
	vector <string> kq;
	texture.loadFromFile("39607.jpg");
	Sprite sprite(texture);

	setTheTextBoxTwoPlayer();
	setTheButtonPlay();

	RenderWindow windowName(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");
	while (windowName.isOpen())
	{
		Event event;
		while (windowName.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				windowName.close();
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
				if (button.isMouseOver(windowName))
				{
					button.setBackColor(Color::Blue);
				}
				else
				{
					button.setBackColor(Color::Green);
				}
				break;

			case Event::MouseButtonPressed:
				if (button.isMouseOver(windowName))
				{
					cout << "Hello " << textbox1.getText() << "\n";
					cout << "Hello " << textbox2.getText() << "\n";
					windowName.close();
				}
				break;

			}
		}
		windowName.clear();
		windowName.draw(sprite);

		windowName.draw(text1);
		windowName.draw(text2);

		windowName.draw(box1);
		windowName.draw(box2);

		textbox1.draw(windowName);
		textbox2.draw(windowName);
		button.draw(windowName);
		windowName.display();
	}
	kq.push_back(textbox1.getText());
	kq.push_back(textbox2.getText());
	return kq;
}

void cPlayerName::setTheTextBoxOnePlayer()
{
	box.setSize(Vector2f(400, 50));
	box.setPosition(Vector2f(300, 380));

	text.setString("Name of player: ");
	text.setFont(font);
	text.setPosition(Vector2f(350, 210));
	text.setCharacterSize(40);

	font.loadFromFile("Cucho Bold.otf");

	textbox.setTextBox(35, Color::Blue, true);
	textbox.setFont(font);
	textbox.setLimit(true, 15);
	textbox.setPosition(Vector2f(310, 385));
}

string cPlayerName::fillNameOnePlayer()
{
	string kq;

	texture.loadFromFile("39607.jpg");
	Sprite sprite(texture);

	setTheTextBoxOnePlayer();
	setTheButtonPlay();
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
					window2.close();
				}
				break;
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
	kq = textbox.getText();
	return kq;
}
