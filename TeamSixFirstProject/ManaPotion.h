#pragma once
#include "Item.h"
#include <string>

class ManaPotion :public Item
{
public:
	ManaPotion();
	virtual bool Use(Character* character) override;
	virtual std::string ItemInfo() const override;
	virtual Item* Clone() const override;
};