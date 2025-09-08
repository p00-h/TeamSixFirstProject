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
	void ResetItem();

	void VisitShop(Character* character);
	
	void DisplayItems();

private:
	std::vector<std::pair<Item*, int>> AvailableItems;

	float SellRatio = 0.5f;

	void ShowShopUI(std::vector<std::pair<Item*, int>> items, int selectnum, Character* character ,float priceratio = 1.f);
	void DeleteShopItem();

	void ShowShopMenu(Character* character);
	void ShowBuyMenu(Character* character);
	void ShowSellMenu(Character* character);

	void BuyItem(std::pair<Item*, int>& item, Character* character);
	void SellItem(std::pair<Item*, int> item, Character* character);
};