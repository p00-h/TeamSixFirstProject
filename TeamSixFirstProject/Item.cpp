#include "Item.h"
#include <string>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

Item::Item(std::string name, int price, int value)
	: Name(name), Price(price), Value(value), IsActive(false) {}

int Item::GetPrice() const
{
	return Price;
}

std::string Item::GetName() const
{
	return Name;
}

void Item::EffectIsOver(Character* character)
{
}

void Item::SetIsActive(bool active)
{
	IsActive = active;
}

void Item::ItemSound()
{
	PlaySound(TEXT("Potion.wav"), NULL, SND_FILENAME | SND_ASYNC);
	Sleep(1000);
}