#pragma once
#include "Header.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class cBall;
class cPaddle
{
	Vector2f position;
	// A RectangleShape object
	RectangleShape cPaddleShape;

	float cPaddleSpeed = .4f;
public:
	cPaddle();
	~cPaddle();
	cPaddle(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	void moveUp(int Top);

	void moveDown(int Bot);

	void update();

	void autoMove(int Top, int Bot, cBall ball);
};
