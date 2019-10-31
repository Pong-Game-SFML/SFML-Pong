#include "cPlayWindow.h"
vector <string> cPlayWindow::playGameTwoPlayer(string name1, string name2)
{
	vector <string> kq;
	cBall ball(550, 400);

	Event event;

	cPaddle paddle1(10, HEIGHT / 2);
	cPaddle paddle2(WIDTH - 20, HEIGHT / 2);

	font_Score.loadFromFile("Facon.ttf");

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");
	
	text[0].setCharacterSize(100);
	text[0].setFillColor(Color(238, 238, 5));
	text[0].setOutlineColor(Color::Red);
	text[0].setOutlineThickness(-5);
	text[0].setPosition(200, 50);
	text[0].setFont(font_Score);

	text[1].setCharacterSize(100);
	text[1].setFillColor(Color(238, 238, 5));
	text[1].setOutlineColor(Color::Red);
	text[1].setOutlineThickness(-5);
	text[1].setPosition(700, 50);
	text[1].setFont(font_Score);

	font_Speed.loadFromFile("BABYK___.TTF");
	speed.setFont(font_Speed);
	speed.setFillColor(Color(150,20,150));
	speed.setOutlineColor(Color(150,150,200));
	speed.setOutlineThickness(10);
	speed.setPosition(400, 700);

	font_name.loadFromFile("Machinegun.ttf");

	namePlayer[0].setCharacterSize(20);
	namePlayer[0].setPosition(50,600);
	namePlayer[0].setString(name1);
	namePlayer[0].setFont(font_name);
	namePlayer[0].setRotation(90);

	namePlayer[1].setCharacterSize(20);
	namePlayer[1].setPosition(950, 720);
	namePlayer[1].setString(name2);
	namePlayer[1].setFont(font_name);
	namePlayer[1].setRotation(-90);



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
			paddle2.moveUp(0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			// move down...
			paddle2.moveDown(HEIGHT);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			// quit...
			// Someone closed the window- bye
			window.close();
		}
		else if (Keyboard::isKeyPressed(Keyboard::W))
		{
			// move up
			paddle1.moveUp(0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			// move up
			paddle1.moveDown(HEIGHT);
		}

		int score1 = ball.getScorePlayer1();
		int score2 = ball.getScorePalyer2();

		string scorePlayer1 = to_string(score1);
		string scorePlayer2 = to_string(score2);

		text[0].setString(scorePlayer1);
		text[1].setString(scorePlayer2);

		int Win = ball.move(WIDTH, HEIGHT, paddle1, paddle2);
		ball.updatePosition();

		paddle1.update();
		paddle2.update();

		window.clear(Color::Black);

		window.draw(text[0]);
		window.draw(text[1]);

		window.draw(paddle1.getShape());
		window.draw(paddle2.getShape());

		string Speed = to_string(fabs(ball.getvx()));
		speed.setString("SPEED: " + Speed);
		window.draw(speed);

		window.draw(ball.getShape());

		window.draw(namePlayer[0]);
		window.draw(namePlayer[1]);
		window.display();
		if (Win == 1)
		{
			window.close();
			kq.push_back(name1);
			kq.push_back("Score: " +scorePlayer1);
		}
		else if (Win == 2)
		{
			window.close();
			kq.push_back(name2);
			kq.push_back("Score: " + scorePlayer2);
		}
	}
	return kq;
}


vector <string> cPlayWindow::playGameOnePlayer(string name)
{
	vector <string> kq ;

	cBall ball(550, 400);

	Event event;

	cPaddle paddle1(10, HEIGHT / 2);

	cPaddle paddle2(WIDTH - 20, HEIGHT / 2);

	font_Score.loadFromFile("Facon.ttf");

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");

	text[0].setCharacterSize(100);
	text[0].setFillColor(Color(238, 238, 5));
	text[0].setOutlineColor(Color::Red);
	text[0].setOutlineThickness(-5);
	text[0].setPosition(200, 50);
	text[0].setFont(font_Score);

	text[1].setCharacterSize(100);
	text[1].setFillColor(Color(238, 238, 5));
	text[0].setOutlineColor(Color::Red);
	text[0].setOutlineThickness(-5);
	text[1].setPosition(700, 50);
	text[1].setFont(font_Score);

	font_Speed.loadFromFile("BABYK___.TTF");
	speed.setFont(font_Speed);
	speed.setFillColor(Color(150, 20, 150));
	speed.setOutlineColor(Color(150, 150, 200));
	speed.setOutlineThickness(10);
	speed.setPosition(400, 700);

	font_name.loadFromFile("Machinegun.ttf");

	namePlayer[1].setCharacterSize(20);
	namePlayer[1].setPosition(950, 720);
	namePlayer[1].setString(name);
	namePlayer[1].setFont(font_name);
	namePlayer[1].setRotation(-90);

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
			paddle2.moveUp(0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			// move down...
			paddle2.moveDown(HEIGHT);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			// quit...
			// Someone closed the window- bye
			window.close();
		}

		int score1 = ball.getScorePlayer1();
		int score2 = ball.getScorePalyer2();

		string scorePlayer1 = to_string(score1);
		string scorePlayer2 = to_string(score2);

		text[0].setString(scorePlayer1);
		text[1].setString(scorePlayer2);

		string Speed = to_string(fabs(ball.getvx()));
		speed.setString("SPEED: " + Speed);

		int Win=ball.move(WIDTH, HEIGHT, paddle1, paddle2);
		ball.updatePosition();

		paddle1.autoMove(0, HEIGHT, ball);

		paddle1.update();
		paddle2.update();

		window.clear(Color::Black);

		window.draw(text[0]);
		window.draw(text[1]);

		window.draw(paddle1.getShape());
		window.draw(paddle2.getShape());

		window.draw(namePlayer[1]);

		window.draw(speed);

		window.draw(ball.getShape());

		window.display();

		if (Win == 1)
		{
			window.close();
			kq.push_back("The Computer");
			kq.push_back("Score: " + scorePlayer1);
		}
		else if (Win == 2)
		{
			window.close();
			kq.push_back(name);
			kq.push_back("Score: " + scorePlayer2);
		}
	}
	return kq;
}


void cPlayWindow :: Winer(vector <string> name)
{
	/*Texture texture;
	texture.loadFromFile("galaxy-wallpaper-11.jpg");
	Sprite sprite(texture);*/

	Font font;
	font.loadFromFile("BARBATRI.TTF");

	Text text[5];
	
	text[0].setCharacterSize(50);
	text[0].setFont(font);
	text[0].setFillColor(Color(223, 0, 41));
	text[0].setString("THE WINER IS");
	text[0].setPosition(370, 20);

	font.loadFromFile("Rainbow Colors - TTF.ttf");
	text[1].setCharacterSize(100);
	text[1].setFont(font);
	text[1].setFillColor(Color(223, 0, 41));
	text[1].setOutlineColor(Color(12,178,192));
	text[1].setOutlineThickness(10);
	text[1].setString(name[0]);
	text[1].setPosition(WIDTH / 2 - text[1].getLocalBounds().width / 2, 150);
	
	text[2].setCharacterSize(30);
	text[2].setFont(font);
	text[2].setFillColor(Color(223, 0, 41));
	text[2].setOutlineColor(Color(12, 178, 192));
	text[2].setOutlineThickness(10);
	text[2].setString(name[1]);
	text[2].setPosition(700,350);

	font.loadFromFile("Cucho Bold.otf");
	text[3].setCharacterSize(30);
	text[3].setFont(font);
	text[3].setFillColor(Color(9, 249, 20));
	text[3].setString("Press Enter to replay!");
	text[3].setPosition(350, 420);
	
	text[4].setCharacterSize(30);
	text[4].setFont(font);
	text[4].setFillColor(Color(9, 249, 20));
	text[4].setString("Press ESC to quit the game!");
	text[4].setPosition(320, 490);


	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Ping Pong Game");
	
	Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyReleased)
			{
				switch (event.key.code)
				{
				case Keyboard::Escape:
				{
					window.close();
					break;
				}
				case Keyboard::Return:
				{
					window.close();
					Control starGame;
					starGame.processGame();
				}
				}
					
			}
		}

		window.clear(Color(120,250,200));
		for (int i = 0;i < 5;i++)
		{
			window.draw(text[i]);
		}
		window.display();
	}
}