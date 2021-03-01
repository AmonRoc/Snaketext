#include "CSnake.h"

CSnake::CSnake(int x, int y, int length, Directions directions, int speed, char pic)
{
	this->m_iHeadX = x;
	this->m_iHeadY = y;
	this->m_iLength = length;
	this->m_enumCurrentDirection = directions;
	this->m_iSpeed = speed;
	this->m_cpic = pic;
	for (size_t i = 0; i < length; i++)
	{
		CUnit unit;
		switch (directions)
		{
		case UP :
			unit.m_x = m_iHeadX;
			unit.m_y = m_iHeadY + i;
			break;
		case DOWN :
			unit.m_x = m_iHeadX;
			unit.m_y = m_iHeadY - i;
			break;
		case LEFT :
			unit.m_x = m_iHeadX + i;
			unit.m_y = m_iHeadY;
			break;
		case RIGHT :
			unit.m_x = m_iHeadX - i;
			unit.m_y = m_iHeadY;
			break;
		default:
			break;
		}
		m_vecBody.push_back(unit);
	}
}

CSnake::~CSnake()
{

}

bool CSnake::changeDirection()
{
	char ch;
	if (_kbhit())
	{
		ch = _getch();	
		if (ch == -32)		// 表明这是方向键
			ch = -_getch();
		else if (ch == 10)
		{
			return false;
		}
			switch (ch)
			{
			case 'w':
			case 'W':
			case -72:		//向上
				if (m_enumCurrentDirection != Directions::DOWN)
					m_enumCurrentDirection = Directions::UP;
				break;
			case 's':
			case 'S':
			case -80:		//向下
				if (m_enumCurrentDirection != Directions::UP)
					m_enumCurrentDirection = Directions::DOWN;
				break;
			case 'a':
			case 'A':
			case -75:		//向左
				if (m_enumCurrentDirection != Directions::RIGHT)
					m_enumCurrentDirection = Directions::LEFT;
				break;
			case 'd':
			case 'D':
			case -77:		//向右
				if (m_enumCurrentDirection != Directions::LEFT)
					m_enumCurrentDirection = Directions::RIGHT;
				break;
			default:
				break;
			}
			return true;
	}
	return true;
}

void CSnake::move()
{
	LastX = m_vecBody.back().m_x;
	LastY = m_vecBody.back().m_y;
	for (size_t i = m_iLength - 1; i > 0; i--)
	{
		m_vecBody[i].m_x = m_vecBody[i - 1].m_x;
		m_vecBody[i].m_y = m_vecBody[i - 1].m_y;
	}
	switch (m_enumCurrentDirection)
	{
	case Directions::UP:
		m_vecBody[0].m_y -= 1;
		break;
	case Directions::DOWN:
		m_vecBody[0].m_y += 1;
		break;
	case Directions::LEFT:
		m_vecBody[0].m_x -= 1;
		break;
	case Directions::RIGHT:
		m_vecBody[0].m_x += 1;
		break;
	default:
		break;
	}
}

bool CSnake::eatFood(CFood* pFood)
{
	if (m_vecBody[0].m_x == pFood->m_x && m_vecBody[0].m_y == pFood->m_y)
	{
		CMap::KSCORE_OFFSET += 50;
		return true;
	}
	else
		return false;
	
}

void CSnake::showSnake()
{
	for (size_t i = 0; i < m_iLength; i++)
	{
		gotoxy(m_vecBody[i].m_x, m_vecBody[i].m_y);
		if (i == 0)
		{
			cout << "#";
		}
		else
		{
			cout << "*";
		}
	}
}

void CSnake::eraseSnake()
{
	gotoxy(LastX,LastY);
	cout << " ";
}

void CSnake::growup()
{
	CUnit c;
	c.m_x = LastX;
	c.m_y = LastY;
	m_vecBody.push_back(c);
	m_iLength++;
}
