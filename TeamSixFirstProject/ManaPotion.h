#pragma once
#include "Item.h"
#include <string>

class ManaPotion :public Item
{
	int ManaRestore;

public:
	ManaPotion();
	virtual void Use(Character* character) override;
};