#pragma once
#include "Item.h"
#include <string>

class AttackBoost :public Item
{
	std::string Name;
	int AttackIncrease;
	int Price;

public:
	AttackBoost();
	virtual std::string GetName() override;
	virtual void Use(Character* character) override;
	int GetPrice() const;
};