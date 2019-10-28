#pragma once
#ifndef CPADDLE_H
#define CPADDLE_H
#include <SFML/Graphics.hpp>
#include "cBall.h"
using namespace sf;

class cBall;

class cPaddle
{
	Vector2f position;
	// A RectangleShape object
	RectangleShape paddleShape;

	float paddleSpeed = .4f;
public:
	
	cPaddle(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	void moveUp(int Top);

	void moveDown(int Bot);

	void update();

	void autoMove(int Top, int Bot, cBall ball);
};

#endif CPADDLE_H