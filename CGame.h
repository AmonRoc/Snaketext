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

	void run();		//运行
	bool checkFailed();		//检测失败
	bool checkLevel();		//检测难度
	void changeInfo();		//改变信息
	void drawGameArea();
	void drawGameInfo();
	void initFood();		//初始化食物

//public:
//	static const int KLEFT = 6;		//距离左边的位置
//	static const int KUP = 1;			//距离顶部的位置
//	static const int KWIDTH = 80;		//宽
//	static const int KHEIGHT = 23;		//高
//	static const int KSCORE_OFFSET = 0;		//得分
//	static const int KLEVEL_OFFSET = 1;		//难度

public:
	CFood* m_pFood;
	CSnake* m_pSnake;
	int m_iScore;
	int m_iLevel;
};

