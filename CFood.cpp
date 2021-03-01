#include "CFood.h"

CFood::CFood(int x, int y, char pic)
{
	this->m_x = x;
	this->m_y = y;
	this->m_pic = pic;
}

CFood::~CFood()
{
	//
}

void CFood::createPos()
{
	CMap food;
	srand((unsigned)time(NULL));
	m_x = (rand() % (food.KWIDTH - 1)) + food.KLEFT + 2;	//要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1;
	m_y = (rand() % (food.KHEIGHT - 3)) + food.KUP + 3;
}
