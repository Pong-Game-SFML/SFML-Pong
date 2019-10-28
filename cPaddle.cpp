
#include "cPaddle.h"

cPaddle::cPaddle(float startX, float startY)
{
	position.x = startX;
	position.y = startY;
	paddleShape.setSize(sf::Vector2f(10, 150));
	paddleShape.setPosition(position);
}


FloatRect cPaddle::getPosition()
{
	return paddleShape.getGlobalBounds();
}

RectangleShape cPaddle::getShape()
{
	return paddleShape;
}

void cPaddle::moveUp(int Top)
{
	if (position.y >= Top)
		position.y -= paddleSpeed;
}

void cPaddle::moveDown(int Bot)
{

	if (position.y + getPosition().height <= Bot)
	{
		position.y += paddleSpeed;
	}
}


void cPaddle::update()
{
	paddleShape.setPosition(position);
}


void cPaddle::autoMove(int Top, int Bot, cBall ball)
{
	float temp = position.y;
	position.y = ball.getPosition().top;
	if (position.y + getPosition().height <= Bot)
	{
		position.y = ball.getPosition().top;
	}
	else
	{
		position.y = temp;
	}

}



