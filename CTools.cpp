#include "CTools.h"

void SetWindowSize(int cols, int lines)
{
	
}
void gotoxy(const int x, const int y)
{
	HANDLE hOut;
	COORD  pos;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ���
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos); //�ƶ����
}

void SetColor(int colorID)//�����ı���ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()//�����ı�����ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED);
}

void CursorDisappears()
{
	//���ù�겻�ɼ�
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;//�ٲ��ɼ�   
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}