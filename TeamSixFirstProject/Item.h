#pragma once
#include <string>

class Character;

class Item
{
protected:
	std::string Name;
	int Price;

	Item(std::string name, int price);

public:
	std::string GetName() const;
	int GetPrice() const;

	virtual void Use(Character* character) = 0;
	
};