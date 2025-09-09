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
	int GetTurn() const;

	void SetTurn(int turn);

	virtual void TurnDecrease(Character* character);

	virtual void Use(Character* character) = 0;
	virtual std::string ItemInfo() const = 0;
	virtual Item* Clone() const = 0;

	void ItemSound();

	virtual ~Item() = default;
};