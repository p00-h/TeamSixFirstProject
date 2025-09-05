#pragma once
#include "Item.h"
#include <string>

class ManaPotion :public Item
{
public:
	ManaPotion();
	virtual void Use(Character* character) override;
	virtual std::string ItemInfo() override;
};