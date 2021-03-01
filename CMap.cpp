#include "CMap.h"

int CMap::KSCORE_OFFSET = 0;
int CMap::KLEVEL_OFFSET = 1;
void CMap::drawGameArea()
{

	for (size_t i = KUP; i < KHEIGHT + KUP; i++)		//���
	{
		gotoxy(KLEFT, i);
		cout << "�U";
	}
	for (size_t i = KUP; i < KHEIGHT + KUP; i++)		//�ұ�
	{
		gotoxy(KLEFT + KWIDTH + 1, i);
		cout << "�U";
	}
	for (size_t i = KLEFT; i <= KWIDTH + KLEFT; i++)		//����
	{
		gotoxy(i, KUP);
		cout << "�T";
	}
	for (size_t i = KLEFT; i <= KWIDTH + KLEFT; i++)		//����
	{
		gotoxy(i, KUP +KHEIGHT);
		cout << "�T";
	}
	for (size_t i = KLEFT; i <= KWIDTH + KLEFT; i++)		//����
	{
		gotoxy(i,KUP + 2);
		cout << "�T";
	}
	gotoxy(KLEFT, KUP);		//���Ͻ�
	cout << "�X";
	gotoxy(KLEFT + KWIDTH + 1, KUP);		//���Ͻ�
	cout << "�[";
	gotoxy(KLEFT, KUP + KHEIGHT);		//���½�
	cout << "�^";
	gotoxy(KLEFT + KWIDTH + 1, KUP + KHEIGHT);		//���½�
	cout << "�a";
	gotoxy(KLEFT, KUP + 2);		//����
	cout << "�d";
	gotoxy(KLEFT + KWIDTH + 1, KUP + 2);		//����
	cout << "�g";
}

void CMap::drawGameInfo()
{


	gotoxy(KLEFT + 2, KUP + 1);
	cout << "��Ϸ��Ϣ��̰����" << "\t" << "��д�ߣ��ֺ���" << "\t\t" << "��ǰ�÷֣�" << KSCORE_OFFSET << "\t" << "��ǰ�ؿ���" << KLEVEL_OFFSET;
}

