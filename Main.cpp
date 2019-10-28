#include "cBall.h"
#include "cPaddle.h"
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	int WIDTH = 1000;
	int HEIGHT = 800;
	cBall ball(550, 400);
	cPaddle paddle1(10, HEIGHT / 2);
	cPaddle paddle2(WIDTH - 20, HEIGHT / 2);
	Event event;


	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close(); //neu bam dau tat tren man hinh thi cua so tat
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			// move up...
			paddle1.moveUp(0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			// move down...
			paddle1.moveDown(HEIGHT);
		}
		else if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			// quit...
			// Someone closed the window- bye
			window.close();
		}
		else if (Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			// move up
			paddle2.moveUp(0);
		}
		else if (Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			// move up
			paddle2.moveDown(HEIGHT);
		}

		ball.move(WIDTH, HEIGHT, paddle1, paddle2);
		paddle1.autoMove(0, HEIGHT, ball);
		paddle2.autoMove(0, HEIGHT, ball);
		ball.updatePosition();
		paddle1.update();
		paddle2.update();
		window.clear(Color(26, 128, 182, 255));
		window.draw(paddle1.getShape());
		window.draw(paddle2.getShape());
		window.draw(ball.getShape());
		window.display();
	}

	return 0;
}