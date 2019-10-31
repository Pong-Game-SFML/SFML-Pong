#include "cBall.h"
cBall::cBall(float initX, float initY)
{
	position.x = initX;
	position.y = initY;
	ballShape.setRadius(10);
	ballShape.setPosition(position);
	ballShape.setFillColor(Color(77, 214, 23));
	//ballShape.setFillColor(Color(15, 240, 250));
	//ballShape.setOutlineColor(Color(250, 20, 10));
	//ballShape.setOutlineThickness(-3);
	//texture.loadFromFile("39607.jpg");
	//Sprite sprite(texture);
	//ballShape.setTextureRect(IntRect(0, 0, 10, 10));
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
	setSpeed();

	vx = -vx; //chuyen huong vx
	position.x = position.x + vx; //cho do nay qua bong len 30 frame
}

void cBall::hitTopOrBottom()
{
	//quay lai vi tri bat dau
	position.x = 550;
	position.y = 400;
	vx = 0.2;
	vy = 0.2;
	score[0] = 0;
	score[1] = 0;
}

void cBall::updatePosition()
{
	position.x = position.x + vx;
	position.y = position.y + vy;
	ballShape.setPosition(position);
}

int cBall::move(int WIDTH, int HEIGHT,cPaddle paddle1, cPaddle paddle2)
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
		return 2;
	}
	if (getPosition().left > WIDTH)
	{
		hitTopOrBottom();
		return 1;
	}

	//Truong hop ball cham paddle 1
	if (getPosition().intersects(paddle1.getPosition()))
	{
		hitPaddles();
		score[0]++;
	}

	//Truong hop ball cham paddle 2
	if (getPosition().intersects(paddle2.getPosition()))
	{
		hitPaddles();
		score[1]++;
	}
	return 0;

}

void cBall::setSpeed()
{
	if (fabs(vx) <= 0.6)
	{
		if (vx <= 0)
		{
			vx = vx - 0.02;
		}
		else if (vx >= 0)
		{
			vx = vx + 0.02;
		}

		if (vy <= 0)
		{
			vy = vy - 0.02;
		}
		else if (vy >= 0)
		{
			vy = vy + 0.02;
		}
	}
	
}

int cBall::getScorePlayer1()
{
	return score[0];
}

int cBall::getScorePalyer2()
{
	return score[1];
}