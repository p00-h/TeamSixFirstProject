#pragma once
#include "Item.h"
#include <string>

class DefenseBoost :public Item
{
public:
	DefenseBoost();
	virtual bool Use(Character* character) override;
	virtual void TurnDecrease(Character* character) override;
	virtual std::string ItemInfo() const override;
	virtual Item* Clone() const override;
};