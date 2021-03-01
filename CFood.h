#pragma once
#include "CUnit.h"
#include "CMap.h"
#include<time.h>
#include<iostream>
using namespace std;
class CFood :
    public CUnit
{
public:
    CFood(int x = 0, int y = 0, char pic = '*');
    virtual ~CFood();
    void createPos();
};

