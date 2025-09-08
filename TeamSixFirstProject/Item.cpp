#include "Item.h"
#include <string>
#include <iostream>

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

int Item::GetTurn() const
{
	return Turn;
}