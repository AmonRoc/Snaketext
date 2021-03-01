#include "CTools.h"

void SetWindowSize(int cols, int lines)
{
	
}
void gotoxy(const int x, const int y)
{
	HANDLE hOut;
	COORD  pos;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); //获取句柄
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos); //移动光标
}

void SetColor(int colorID)//设置文本颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()//设置文本背景色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED);
}

void CursorDisappears()
{
	//设置光标不可见
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;//假不可见   
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}