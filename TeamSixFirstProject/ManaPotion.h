#pragma once
#include "Item.h"
#include <string>

class ManaPotion :public Item
{

	std::string Name;
	int ManaRestore;
	int Price;

public:
	ManaPotion();
	virtual bool Use(Character* character) override;
	virtual std::string ItemInfo() const override;
	virtual Item* Clone() const override;
	virtual bool IsDurationBased() const override;
};