#pragma once
#include "cPaddle.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class cBall
{
private:
	Vector2f position; //vi tri cua ball
	CircleShape ballShape; //ve ball co dang hinh tron
	float vx = .2f; //van toc theo chieu x
	float vy = .2f; //van toc theo chieu y
public:
	cBall(float initX, float initY); //constructor

	//lay cac thong so private cua class
	FloatRect getPosition(); 
	CircleShape getShape();
	float getvx();
	float getvy();

	//Xet cac truong hop va cham cua ball
	void hitSides();
	void hitPaddles();
	void hitTopOrBottom();

	void updatePosition(); //cap nhat lai vi tri cua ball

	void move(int WIDTH, int HEIGHT);
};

