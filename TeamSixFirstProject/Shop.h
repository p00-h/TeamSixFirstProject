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


	void VisitShop(Character* character);
	void ShowShopMenu(Character* character);
	void ShowBuyMenu(Character* character);
	void DisplayItems();


	void BuyItem(Item* item, Character* character);
	void SellItem(int Index, Character* character, int ItemCount = 1);

private:
	std::vector<std::pair<Item*, int>> AvailableItems;


};