#pragma once
#include "Item.h"
#include <string>

class ManaPotion :public Item
{
<<<<<<< HEAD
	std::string Name;
	int ManaRestore;
	int Price;

=======
>>>>>>> parent of 5e63b35 (Merge branch 'main' into dev)
public:
	ManaPotion();
	virtual std::string GetName() override;
	virtual void Use(Character* character) override;
};