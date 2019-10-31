#pragma once
#include "Header.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class cPlayerName
{
private:
	RectangleShape box1;
	RectangleShape box2;
	Text text1;
	Text text2;
	TextBox textbox1;
	TextBox textbox2;

	RectangleShape box;
	Text text;
	TextBox textbox;

	Button button;
	Texture texture;
	Font font;

public:
	void setTheTextBoxTwoPlayer();

	void setTheButtonPlay();

	vector <string> fillNameTwoPlayer();

	void setTheTextBoxOnePlayer();

	string fillNameOnePlayer();
};
