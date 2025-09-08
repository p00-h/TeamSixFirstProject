#include "Item.h"
#include <string>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

Item::Item(std::string name, int price, int value, int turn)
	: Name(name), Price(price), Value(value), Turn(turn) {}

int Item::GetPrice() const
{
	return Price;
}

std::string Item::GetName() const
{
	return Name;
}

void Item::TurnDecrease(Character* character)
{

}

void Item::ItemSound()
{
	PlaySound(TEXT("Potion.wav"), NULL, SND_FILENAME | SND_ASYNC);
	Sleep(1000);
}

int Item::GetTurn() const
{
	return Turn;
}