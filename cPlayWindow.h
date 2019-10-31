#pragma once
#include "Header.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class cPlayWindow
{
private:
	int WIDTH = 1000;
	int HEIGHT = 800;
	Font font_Score;
	Text text[2];
	Font font_Speed;
	Text speed;
	Text namePlayer[2];
	Font font_name;
public:
	vector <string> playGameTwoPlayer(string name1, string name2);

	vector <string> playGameOnePlayer(string name);

	void Winer(vector <string> name);

};
