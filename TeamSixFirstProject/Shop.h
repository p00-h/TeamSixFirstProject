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
	void ShowSellMenu(Character* character);
	void DisplayItems();


	void BuyItem(std::pair<Item*, int> item, Character* character);
	void SellItem(std::pair<Item*, int> item, Character* character);

private:
	std::vector<std::pair<Item*, int>> AvailableItems;

	float SellRatio = 0.5f;

};