#pragma once
#include "Item.h"
#include <string>

class AttackBoost :public Item
{
<<<<<<< HEAD
	std::string Name;
	int AttackIncrease;
	int Price;

=======
>>>>>>> parent of 5e63b35 (Merge branch 'main' into dev)
public:
	AttackBoost();
	virtual std::string GetName() override;
	virtual void Use(Character* character) override;
};