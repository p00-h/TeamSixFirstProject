#pragma once
#include "Item.h"
#include <string>

class AttackBoost :public Item
{
public:
	AttackBoost();
	virtual void Use(Character* character) override;
	virtual std::string ItemInfo() override;
	virtual Item* Clone() const override;
};