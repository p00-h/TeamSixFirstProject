#pragma once
#include "Item.h"
#include <string>

class HealthPotion :public Item
{
<<<<<<< HEAD
	std::string Name;
	int HealthRestore;
	int Price;

=======
>>>>>>> parent of 5e63b35 (Merge branch 'main' into dev)
public:
	HealthPotion();
	virtual std::string GetName() override;
	virtual void Use(Character* character) override;
};