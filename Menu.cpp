#include "Menu.h"

Menu::Menu()
{
	font.loadFromFile("Leoscar Sans Serif.ttf");

	text[0].setFont(font);
	text[0].setPosition(425, 355);
	text[0].setCharacterSize(40);
	text[0].setFillColor(Color::Green);
	text[0].setString("2 PLAYERS");

	text[1].setFont(font);
	text[1].setPosition(445, 433);
	text[1].setCharacterSize(40);
	text[1].setFillColor(Color::White);
	text[1].setString("1 PLAYER");

	text[2].setFont(font);
	text[2].setPosition(485, 515);
	text[2].setCharacterSize(40);
	text[2].setFillColor(Color::White);
	text[2].setString("EXIT");

	box[0].setPosition(400, 350);
	box[0].setFillColor(Color::Transparent);
	box[0].setSize(Vector2f(230, 55));
	box[0].setOutlineColor(Color::Green);
	box[0].setOutlineThickness(5);

	box[1].setPosition(400, 430);
	box[1].setFillColor(Color::Transparent);
	box[1].setSize(Vector2f(230, 55));
	box[1].setOutlineColor(Color::White);
	box[1].setOutlineThickness(5);

	box[2].setPosition(400, 510);
	box[2].setFillColor(Color::Transparent);
	box[2].setSize(Vector2f(230, 55));
	box[2].setOutlineColor(Color::White);
	box[2].setOutlineThickness(5);

	selectItem = 0;
}

void Menu::draw(RenderWindow& window)
{
	for (int i = 0; i < OBJECTS; i++)
	{
		window.draw(box[i]);
		window.draw(text[i]);
	}
}

void Menu::moveUp()
{
	if (selectItem - 1 >= 0)
	{
		text[selectItem].setColor(Color::White);
		box[selectItem].setOutlineColor(Color::White);
		selectItem--;
		text[selectItem].setColor(Color::Green);
		box[selectItem].setOutlineColor(Color::Green);
	}
}

void Menu::moveDown()
{
	if (selectItem + 1 < OBJECTS)
	{
		text[selectItem].setColor(Color::White);
		box[selectItem].setOutlineColor(Color::White);
		selectItem++;
		text[selectItem].setColor(Color::Green);
		box[selectItem].setOutlineColor(Color::Green);
	}
}

int Menu::getChoose()
{
	return selectItem;
}