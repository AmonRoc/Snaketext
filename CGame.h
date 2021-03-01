#pragma once
#include "CFood.h"
#include "CSnake.h"
#include "CTools.h"
#include "CMap.h"
#include <iostream>
using namespace std;
class CGame
{
public:
	CGame();
	virtual ~CGame();

	void run();		//����
	bool checkFailed();		//���ʧ��
	bool checkLevel();		//����Ѷ�
	void changeInfo();		//�ı���Ϣ
	void drawGameArea();
	void drawGameInfo();
	void initFood();		//��ʼ��ʳ��

//public:
//	static const int KLEFT = 6;		//������ߵ�λ��
//	static const int KUP = 1;			//���붥����λ��
//	static const int KWIDTH = 80;		//��
//	static const int KHEIGHT = 23;		//��
//	static const int KSCORE_OFFSET = 0;		//�÷�
//	static const int KLEVEL_OFFSET = 1;		//�Ѷ�

public:
	CFood* m_pFood;
	CSnake* m_pSnake;
	int m_iScore;
	int m_iLevel;
};

