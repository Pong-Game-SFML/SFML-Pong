#pragma once
#define SFML_NO_DEPRECATED_WARNINGS
#include <SFML/Graphics.hpp>
using namespace sf;
#define OBJECTS 3

class EndMenu
{
private:
	int selectItem;
	Font font;
	RectangleShape box[OBJECTS];
	Text text[OBJECTS];
public:
	EndMenu(int WIDTH, int HEIGHT); 
	void draw(RenderWindow& window);//ve end menu len man hinh
	void moveUp();
	void moveDown();
	int getChoose(); //tra ve lua chon trong menu
};

