#pragma once
#include "Item.h"
#include <string>

class HealthPotion :public Item
{
	int HealthRestore;

public:
	HealthPotion();
	virtual void Use(Character* character) override;
};