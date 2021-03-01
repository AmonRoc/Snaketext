#include "CUnit.h"

CUnit::CUnit(int x, int y, char pic)
{
	this->m_x = x;
	this->m_y = y;
	this->m_pic = pic;
}

CUnit::~CUnit()
{
	//
}

void CUnit::show()
{
	gotoxy(m_x, m_y);
	cout << "*";
}

void CUnit::erase()
{
	gotoxy(m_x, m_y);
	cout << " ";
}
