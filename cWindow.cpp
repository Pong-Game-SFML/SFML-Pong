#include "cWindow.h"



cWindow::cWindow()
{
}


cWindow::~cWindow()
{
}


void cWindow :: drawTheGameOverWindow(int WIDTH, int HEIGHT)
{
	Font font;
	font.loadFromFile("BRAD.TTF");
	Text text("GAME OVER", font, 50);
	RenderWindow windowGameOver(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");
	while (windowGameOver.isOpen())
	{
		Event event;
		while (windowGameOver.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				windowGameOver.close();
			}
		}
		
		windowGameOver.clear(Color(150, 250, 100, 255));
		windowGameOver.draw(text);
		windowGameOver.display();
	}
	

}
