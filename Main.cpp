#include "cBall.h"
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	int WIDTH = 1000;
	int HEIGHT = 800;
	cBall ball(550, 400);
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

		ball.move(WIDTH, HEIGHT);
		ball.updatePosition();
		window.clear(Color(26, 128, 182, 255));
		window.draw(ball.getShape());
		window.display();
	}

	return 0;
}