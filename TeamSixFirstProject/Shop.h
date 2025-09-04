#pragma once
#include <vector>

class Character;
class Item;

using namespace std;

class Shop
{
public:
	Shop();

	void DisplayItems();
	void BuyItem(int Index, Character* Player);
	void SellItem(int Index, Character* Player);

private:
	vector<Item*> AvailableItems;

};