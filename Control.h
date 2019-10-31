#pragma once 
#include <SFML/Graphics.hpp>
#include "Header.h"
using namespace std;
using namespace sf;

class Control
{
private:
	int WIDTH = 1000;
	int HEIGHT = 800;

public:
	void processGame();
};