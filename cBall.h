#pragma once
#include "Header.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class cPaddle;
class cBall
{
private:
	Vector2f position;// vi tri cua ball
	CircleShape ballShape; //ve ball co dang hinh tron
	float vx = 0.2; //van toc theo chieu x
	float vy = 0.2; //van toc theo chieu y
	float speed = 0;
	int score[2] = { 0 };
	Texture texture;
public:
	cBall(float initX, float initY); //constructor

	//lay cac thong so private cua class
	FloatRect getPosition();

	CircleShape getShape();

	float getvx();

	float getvy();

	void setSpeed();

	//Xet cac truong hop va cham cua ball
	void hitSides();

	void hitPaddles();

	void hitTopOrBottom();

	void updatePosition(); //cap nhat lai vi tri cua ball

	int move(int WIDTH, int HEIGH,cPaddle paddle1, cPaddle paddle2);

	int getScorePlayer1();
	int getScorePalyer2();
};


