#pragma once
#include <string>

class Character;

class Item
{
protected:
	std::string Name;
	int Price;
	int Value;

	Item(std::string name, int price, int value);

public:
	std::string GetName() const;
	int GetPrice() const;
	
	virtual void ItemInfo() = 0;
	virtual void Use(Character* character) = 0;
};