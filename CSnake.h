#pragma once
#include "CFood.h"
#include "CUnit.h"
#include "CMap.h"
#include "conio.h"
#include "CTools.h"
#include <vector>
#include <iostream>
using namespace std;

typedef enum
{
	UP, DOWN, LEFT, RIGHT
}Directions;

class CSnake
{
public:
	CSnake(int x = 40, int y = 20, int length = 4, Directions directions = RIGHT, int speed = 500, char pic = '*');
	virtual ~CSnake();

	bool changeDirection();		//¡ü ¡ý ¡û ¡ú
	void move();
	bool eatFood(CFood* pFood);
	void showSnake();
	void eraseSnake();
	void growup();

public:
	int LastX = 0;
	int LastY = 0;
	int m_iLength;
	int m_iHeadX;
	int m_iHeadY;
	int m_iSpeed;
	int m_cpic;
	Directions m_enumCurrentDirection;
	vector<CUnit> m_vecBody;
};

