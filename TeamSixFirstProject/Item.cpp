#include "Item.h"
#include <string>

Item::Item(std::string name, int price) : Name(name), Price(price) {}

int Item::GetPrice() const
{
	return Price;
}

std::string Item::GetName() const
{
	return Name;
}