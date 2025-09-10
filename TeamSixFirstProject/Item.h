#pragma once
#include <string>

class Character;

class Item
{
public:
	virtual std::string GetName() = 0;
	virtual void Use(Character* character) = 0;
};