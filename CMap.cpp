#include "CMap.h"

int CMap::KSCORE_OFFSET = 0;
int CMap::KLEVEL_OFFSET = 1;
void CMap::drawGameArea()
{

	for (size_t i = KUP; i < KHEIGHT + KUP; i++)		//左边
	{
		gotoxy(KLEFT, i);
		cout << "║";
	}
	for (size_t i = KUP; i < KHEIGHT + KUP; i++)		//右边
	{
		gotoxy(KLEFT + KWIDTH + 1, i);
		cout << "║";
	}
	for (size_t i = KLEFT; i <= KWIDTH + KLEFT; i++)		//上面
	{
		gotoxy(i, KUP);
		cout << "═";
	}
	for (size_t i = KLEFT; i <= KWIDTH + KLEFT; i++)		//下面
	{
		gotoxy(i, KUP +KHEIGHT);
		cout << "═";
	}
	for (size_t i = KLEFT; i <= KWIDTH + KLEFT; i++)		//里面
	{
		gotoxy(i,KUP + 2);
		cout << "═";
	}
	gotoxy(KLEFT, KUP);		//左上角
	cout << "╔";
	gotoxy(KLEFT + KWIDTH + 1, KUP);		//右上角
	cout << "╗";
	gotoxy(KLEFT, KUP + KHEIGHT);		//左下角
	cout << "╚";
	gotoxy(KLEFT + KWIDTH + 1, KUP + KHEIGHT);		//右下角
	cout << "╝";
	gotoxy(KLEFT, KUP + 2);		//里左
	cout << "╠";
	gotoxy(KLEFT + KWIDTH + 1, KUP + 2);		//里右
	cout << "╣";
}

void CMap::drawGameInfo()
{


	gotoxy(KLEFT + 2, KUP + 1);
	cout << "游戏信息：贪吃蛇" << "\t" << "编写者：贾海鹏" << "\t\t" << "当前得分：" << KSCORE_OFFSET << "\t" << "当前关卡：" << KLEVEL_OFFSET;
}

