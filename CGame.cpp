#include "CGame.h"

CGame::CGame()
{
	this->m_iLevel = CMap::KLEVEL_OFFSET;
	this->m_iScore = CMap::KSCORE_OFFSET;
	m_pSnake = new CSnake;
	m_pFood = new CFood;
}

CGame::~CGame()
{
	delete m_pSnake;
	delete m_pFood;
	m_pSnake = NULL;
	m_pFood = NULL;
}

void CGame::run()
{
	CursorDisappears();		//取消光标
	drawGameArea();			//初始化地图
	drawGameInfo();			//初始化信息
	initFood();				//初始化食物
	while (checkFailed())		//判断是否失败
	{
		m_pSnake->changeDirection();		//控制方向
		m_pSnake->move();					//蛇移动
		m_pSnake->showSnake();				//显示蛇
		m_pSnake->eraseSnake();				//擦除蛇尾
		if (m_pSnake->eatFood(m_pFood))		//判断是否吃食物
		{
			drawGameInfo();			//修改信息
			m_pSnake->growup();		//蛇变长
			//m_pFood->erase();		//食物消失
			initFood();	//生成新食物
			/*if (checkLevel())
			{
		
				system("cls");
				cout << "恭喜你过关了！" << endl;
				cout << "你的分数为：";
				cout << CMap::KSCORE_OFFSET << endl;
				break;
			}*/
		}
		
		Sleep(m_pSnake->m_iSpeed);		//蛇的移动速度
		//Sleep(100);
	}

}

bool CGame::checkFailed()
{
	if (m_pSnake->m_vecBody[0].m_x > CMap::KLEFT + 1 && m_pSnake->m_vecBody[0].m_x < CMap::KLEFT + 1 + CMap::KWIDTH && m_pSnake->m_vecBody[0].m_y > CMap::KUP + 2 && m_pSnake->m_vecBody[0].m_y < CMap::KUP + CMap::KHEIGHT)
	{
		for (size_t i = 1; i < m_pSnake->m_iLength; i++)
		{
			if (m_pSnake->m_vecBody[i].m_x == m_pSnake->m_vecBody[0].m_x   &&m_pSnake->m_vecBody[i].m_y ==m_pSnake->m_vecBody[0].m_y )
				return false;
		}
		return true;
	}
	else
		return false;
}

bool CGame::checkLevel()
{
	if (CMap::KSCORE_OFFSET >= 1000)
	{
		return true;
	}
	else
		return false;
}

void CGame::changeInfo()
{
	for (size_t i = 1; i < 10; i++)
	{
		if (CMap::KSCORE_OFFSET >= i*50 && CMap::KSCORE_OFFSET < (i + 1)*50)
		{
			m_pSnake->m_iSpeed = 500 - i*50;
			CMap::KLEVEL_OFFSET = 1 + i;
		}
	}
	
}

void CGame::drawGameArea()
{
	CMap Mymap;
	Mymap.drawGameArea();
}

void CGame::drawGameInfo()
{
	changeInfo();
	CMap map;
	map.drawGameInfo();
}

void CGame::initFood()
{
	m_pFood->createPos();
	for (size_t i = 0; i < m_pSnake->m_iLength; i++)		//防止食物与蛇身重合
	{
		if (m_pFood->m_x == m_pSnake->m_vecBody[i].m_x && m_pFood->m_y == m_pSnake->m_vecBody[i].m_y)
		{
			m_pFood->createPos();
		}
	}
	m_pFood->show();
}
