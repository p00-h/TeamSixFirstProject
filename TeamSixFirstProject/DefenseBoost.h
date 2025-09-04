#pragma once
#include "Item.h"
#include <string>

class DefenseBoost :public Item
{
	int DefenseIncrease;

public:
	DefenseBoost();
	virtual void Use(Character* character) override;
};