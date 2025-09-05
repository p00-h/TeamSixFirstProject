#pragma once
#include "Item.h"
#include <string>

class DefenseBoost :public Item
{
public:
	DefenseBoost();
	virtual void Use(Character* character) override;
	virtual std::string ItemInfo() override;
};