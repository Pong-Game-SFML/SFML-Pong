#include "Bat.h"



Bat::Bat()
{
}


Bat::~Bat()
{
}


Bat::Bat(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	batShape.setSize(sf::Vector2f(10,150));
	batShape.setPosition(position);
}


FloatRect Bat::getPosition()
{
	return batShape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
	return batShape;
}

void Bat::moveUp(int Top)
{
	if (position.y >= Top)
	position.y -= batSpeed;
}

void Bat::moveDown(int Bot)
{
	
	if (position.y + getPosition().height<= Bot)
	{
		position.y += batSpeed;
	}
	}
	

void Bat::update()
{
	batShape.setPosition(position);
}


