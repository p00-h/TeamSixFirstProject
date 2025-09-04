#pragma once
#include "Item.h"
#include <string>

class AttackBoost :public Item
{
	int AttackIncrease;

public:
	AttackBoost();
	virtual void Use(Character* character) override;
};