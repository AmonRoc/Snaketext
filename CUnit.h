#pragma once
#include "CTools.h"
#include<Windows.h>
#include <iostream>
using namespace std;
class CUnit
{
public:
	CUnit(int x = 0, int y = 0, char pic = '*');
	virtual ~CUnit();
	void show();
	void erase();
public:
	int m_x;
	int m_y;
	char m_pic;
};

