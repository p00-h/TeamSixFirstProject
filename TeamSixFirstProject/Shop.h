#pragma once
#include <vector>
#include <map>

class Character;
class Item;

class Shop
{
public:
	Shop();
	~Shop();
	
	void DisplayItems();
	void BuyItem(int Index, Character* Player);
	//void SellItem(int Index, Character* Player);

private:
	std::vector<std::pair<Item*, int>> AvailableItems;


};