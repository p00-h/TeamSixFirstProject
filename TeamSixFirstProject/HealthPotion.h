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
	virtual std::string GetName() override;
	virtual void Use(Character* character) override;
};