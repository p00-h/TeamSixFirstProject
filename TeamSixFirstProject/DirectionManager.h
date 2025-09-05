#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

class DirectionManager
{
protected:
	int input;
public:
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ENTER 13
	int Direction();
};