#pragma once
#include "Item.h"
#include <string>

class DefenseBoost :public Item
{
	std::string Name;
	int DefenseIncrease;

public:
	DefenseBoost();
	virtual std::string GetName() override;
	virtual void Use(Character* character) override;
};