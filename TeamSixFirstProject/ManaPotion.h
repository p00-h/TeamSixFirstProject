#pragma once
#include "Item.h"
#include <string>

class ManaPotion :public Item
{
	std::string Name;
	int ManaRestore;

public:
	ManaPotion();
	virtual std::string GetName() override;
	virtual void Use(Character* character) override;
};