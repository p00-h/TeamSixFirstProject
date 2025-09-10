#pragma once
#include <string>

class Character;

class Item
{
protected:
	std::string Name;
	int Price;
	int Value;
	bool IsActive;

	Item(std::string name, int price, int value);

public:
	std::string GetName() const;
	int GetPrice() const;

	virtual bool Use(Character* character) = 0;
	virtual std::string ItemInfo() const = 0;
	virtual Item* Clone() const = 0;
	virtual bool IsDurationBased() const = 0;

	virtual void EffectIsOver(Character* character);

	void ItemSound();

	virtual ~Item() = default;
};