
#pragma once
#include "Item.h"
#include <string>

class HealthPotion :public Item
{

	std::string Name;
	int HealthRestore;
	int Price;


public:
	HealthPotion();
	virtual bool Use(Character* character) override;
	virtual std::string ItemInfo() const override;
	virtual Item* Clone() const override;
	virtual bool IsDurationBased() const override;
};