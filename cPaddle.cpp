#include "cPaddle.h"
cPaddle::cPaddle()
{
}


cPaddle::~cPaddle()
{
}


cPaddle::cPaddle(float startX, float startY)
{
	position.x = startX;
	position.y = startY;
	cPaddleShape.setSize(sf::Vector2f(10, 150));
	cPaddleShape.setPosition(position);
	cPaddleShape.setFillColor(Color(6, 232, 203));
}


FloatRect cPaddle::getPosition()
{
	return cPaddleShape.getGlobalBounds();
}

RectangleShape cPaddle::getShape()
{
	return cPaddleShape;
}

void cPaddle::moveUp(int Top)
{
	if (position.y >= Top)
	{
		position.y -= cPaddleSpeed;
	}
}

void cPaddle::moveDown(int Bot)
{

	if (position.y + getPosition().height <= Bot)
	{
		position.y += cPaddleSpeed;
	}
}


void cPaddle::update()
{
	cPaddleShape.setPosition(position);
}


void cPaddle::autoMove(int Top, int Bot, cBall ball)
{

	if (position.y + getPosition().height < ball.getPosition().top)
	{
		moveDown(Bot);
	}
	else if (position.y > ball.getPosition().top)
	{
		moveUp(Top);
	}
	/*else

		float temp = position.y;
		position.y = ball.getPosition().top;
		if (position.y + getPosition().height > Bot)
		{
			position.y = temp;
		}
	*/
}
