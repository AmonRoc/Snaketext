#pragma once
#include "CTools.h"
#include <iostream>
using namespace std;
class CMap
{
public:
	void drawGameArea();				//��Ϸ����
	void drawGameInfo();				//��Ϸ��Ϣ

public:
	static const int KLEFT = 6;		//������ߵ�λ��
	static const int KUP = 1;			//���붥����λ��
	static const int KWIDTH = 80;		//��
	static const int KHEIGHT = 23;		//��
	static int KSCORE_OFFSET;		//�÷�
	static int KLEVEL_OFFSET;		//�Ѷ�
};