#include "Control.h"

void Control :: processGame()
{
	RenderWindow beginWindow(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");

	cBeginMenu begin;

	Event event;

	if (beginWindow.isOpen())
	{
		while (beginWindow.isOpen())
		{
			while (beginWindow.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					beginWindow.close();
				}
				else if (event.type == Event::KeyReleased)
				{
					if (event.key.code == Keyboard::Up)
					{
						begin.moveUp();
					}
					else if (event.key.code == Keyboard::Down)
					{
						begin.moveDown();
					}
					else if (event.key.code == Keyboard::Return)
					{
						switch (begin.getChoose())
						{
						case 0:
						{
							cout << "2 players" << endl;
							beginWindow.close();
							cPlayerName player;
							vector <string> kq = player.fillNameTwoPlayer();
							cPlayWindow playGame;
							vector <string> winer = playGame.playGameTwoPlayer(kq[0], kq[1]);
							playGame.Winer(winer);
							break;
						}
						case 1:
						{
							cout << "1 players" << endl;
							beginWindow.close();
							cPlayerName player;
							string kq = player.fillNameOnePlayer();
							cPlayWindow playGame;
							vector <string> winer = playGame.playGameOnePlayer(kq);
							playGame.Winer(winer);
							break;
						}
						case 2:
							beginWindow.close();
							break;
						}
					
					}
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				beginWindow.close();
			}
			beginWindow.clear();
			begin.draw(beginWindow);
			beginWindow.display();
		}
	}
}