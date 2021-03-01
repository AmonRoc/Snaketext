#pragma once
#ifndef CTOOLS_H
#define CTOOLS_H
#include "windows.h"
#include "CMap.h"
#include <iostream>
using namespace std;


void SetWindowSize(int cols, int lines);
void gotoxy(const int x, const int y);
void SetColor(int colorID);
void SetBackColor();
void CursorDisappears();
#endif // TOOLS_H