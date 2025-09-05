#include "Item.h"
#include <string>
#include <iostream>

Item::Item(std::string name, int price, int value) : Name(name), Price(price), Value(value) {}

int Item::GetPrice() const
{
	return Price;
}

std::string Item::GetName() const
{
	return Name;
}