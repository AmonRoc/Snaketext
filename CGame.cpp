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
	CursorDisappears();		//ȡ�����
	drawGameArea();			//��ʼ����ͼ
	drawGameInfo();			//��ʼ����Ϣ
	initFood();				//��ʼ��ʳ��
	while (checkFailed())		//�ж��Ƿ�ʧ��
	{
		m_pSnake->changeDirection();		//���Ʒ���
		m_pSnake->move();					//���ƶ�
		m_pSnake->showSnake();				//��ʾ��
		m_pSnake->eraseSnake();				//������β
		if (m_pSnake->eatFood(m_pFood))		//�ж��Ƿ��ʳ��
		{
			drawGameInfo();			//�޸���Ϣ
			m_pSnake->growup();		//�߱䳤
			//m_pFood->erase();		//ʳ����ʧ
			initFood();	//������ʳ��
			/*if (checkLevel())
			{
		
				system("cls");
				cout << "��ϲ������ˣ�" << endl;
				cout << "��ķ���Ϊ��";
				cout << CMap::KSCORE_OFFSET << endl;
				break;
			}*/
		}
		
		Sleep(m_pSnake->m_iSpeed);		//�ߵ��ƶ��ٶ�
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
	for (size_t i = 0; i < m_pSnake->m_iLength; i++)		//��ֹʳ���������غ�
	{
		if (m_pFood->m_x == m_pSnake->m_vecBody[i].m_x && m_pFood->m_y == m_pSnake->m_vecBody[i].m_y)
		{
			m_pFood->createPos();
		}
	}
	m_pFood->show();
}
