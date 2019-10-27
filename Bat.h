#pragma once
#include <SFML/Graphics.hpp>
#include "cBall.h"
using namespace sf;
class Bat
{
	Vector2f position;
	// A RectangleShape object
	RectangleShape batShape;

	float batSpeed = .4f;
public:
	Bat();
	~Bat();
	Bat(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	void moveUp(int Top);

	void moveDown(int Bot);

	void update();

	void autoMove(int Top, int Bot, cBall ball);
};

