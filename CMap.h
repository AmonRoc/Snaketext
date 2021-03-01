#pragma once
#include "CTools.h"
#include <iostream>
using namespace std;
class CMap
{
public:
	void drawGameArea();				//游戏界面
	void drawGameInfo();				//游戏信息

public:
	static const int KLEFT = 6;		//距离左边的位置
	static const int KUP = 1;			//距离顶部的位置
	static const int KWIDTH = 80;		//宽
	static const int KHEIGHT = 23;		//高
	static int KSCORE_OFFSET;		//得分
	static int KLEVEL_OFFSET;		//难度
};