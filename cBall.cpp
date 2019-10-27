#include "cBall.h"
cBall::cBall(float initX, float initY)
{
	position.x = initX;
	position.y = initY;

	ballShape.setRadius(10);
	ballShape.setPosition(position);
}

FloatRect cBall::getPosition()
{
	return ballShape.getGlobalBounds();
}

CircleShape cBall::getShape()
{
	return ballShape;
}

float cBall::getvx()
{
	return vx;
}

float cBall::getvy()
{
	return vy;
}

void cBall::hitSides()
{
	vy = -vy; //chuyen huong vy
}

void cBall::hitPaddles()
{
	vx = -vx; //chuyen huong vx
	position.x = position.x + vx; //cho do nay qua bong len 30 frame
}

void cBall::hitTopOrBottom()
{
	//quay lai vi tri bat dau
	position.x = 550;
	position.y = 400;
}

void cBall::updatePosition()
{
	position.x = position.x + vx;
	position.y = position.y + vy;
	ballShape.setPosition(position);
}

void cBall::move(int WIDTH, int HEIGHT)
{
	//Truong hop ball cham sides
	if (getPosition().top < 0)
	{
		hitSides();
	}
	if ((getPosition().top + getPosition().height) > HEIGHT)
	{
		hitSides();
	}

	//Truong hop khong hung duoc ball
	if (getPosition().left < 0) //at top
	{
		hitTopOrBottom();
	}
	if (getPosition().left > WIDTH)
	{
		hitTopOrBottom();
	}
	// Truong hop hung duoc ball

}