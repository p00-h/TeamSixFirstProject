#include "Item.h"
#include <string>
#include <iostream>

Item::Item(std::string name, int price, int value, int turn)
	: Name(name), Price(price), Value(value), Turn(turn) {}

int Item::GetPrice() const
{
	return Price;
}

void Item::TurnDecrease()
{
	--Turn;
	std::cout << Name << "의 효과가 " << Turn << "턴 남았습니다." << std::endl;
}

std::string Item::GetName() const
{
	return Name;
}