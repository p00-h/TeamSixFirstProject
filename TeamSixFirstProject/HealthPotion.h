#pragma once
#include "Item.h"
#include <string>

class HealthPotion :public Item
{
public:
	HealthPotion();
	virtual void Use(Character* character) override;
	virtual void ItemInfo() override;
};