#pragma once
#include "Item.h"
#include <string>

class DefenseBoost :public Item
{


	std::string Name;
	int DefenseIncrease;
	int Price;


public:
	DefenseBoost();
	virtual bool Use(Character* character) override;
	virtual std::string ItemInfo() const override;
	virtual Item* Clone() const override;
	virtual bool IsDurationBased() const override;
	virtual void EffectIsOver(Character* character) override;
};