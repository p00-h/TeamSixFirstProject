#pragma once
#include "Item.h"
#include <string>

class DefenseBoost :public Item
{
<<<<<<< HEAD
	std::string Name;
	int DefenseIncrease;
	int Price;

=======
>>>>>>> parent of 5e63b35 (Merge branch 'main' into dev)
public:
	DefenseBoost();
	virtual std::string GetName() override;
	virtual void Use(Character* character) override;
};