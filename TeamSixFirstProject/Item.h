#pragma once
#include <string>

class Character;

class Item
{
protected:
	std::string Name;
	int Price;
	int Value;
	int Turn;

	Item(std::string name, int price, int value, int turn);

public:
	std::string GetName() const;
	int GetPrice() const;
	void TurnDecrease();
	virtual std::string ItemInfo() = 0;

	virtual void Use(Character* character) = 0;
	virtual void ExpireEffect(Character* character);
	virtual Item* Clone() const = 0;

	virtual ~Item() = default;
};