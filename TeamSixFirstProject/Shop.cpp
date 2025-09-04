#include <map>
#include <vector>
#include <utility>
#include <iostream>
#include "Shop.h"
#include "Player.h"
#include "AttackBoost.h"
#include "DefenseBoost.h"
#include "HealthPotion.h"
#include "ManaPotion.h"

using namespace std;

Shop::Shop()
{
	AvailableItems.push_back({ new AttackBoost(), 3});
	AvailableItems.push_back({ new DefenseBoost(), 3});
	AvailableItems.push_back({ new HealthPotion(), 3});
	AvailableItems.push_back({ new ManaPotion(), 3});


	cout << "상점에 오신 걸 환영합니다!" << endl;

}

Shop::~Shop()
{
	for (auto& it : AvailableItems)
	{
		delete it.first;
	}
	AvailableItems.clear();
}


void Shop::DisplayItems()
{
	cout << "구매 가능한 아이템:" << endl;
	int i = 1;
	for (auto& it : AvailableItems)
	{
		cout << i << ". " << it.first->GetName() << " " << it.second << "개" << endl; //<< it.first->;
		++i;
	}
}

void Shop::BuyItem(int Index, Character* Player, int ItemCount)
{
	
	Item* buyItem = AvailableItems[Index - 1].first;

	if (Player->SpendGold(buyItem->GetPrice()))
	{
		Player->AddItem(buyItem, ItemCount);

		cout << buyItem->GetName() << "을(를) 구매했습니다."

		
	}

}

void Shop::SellItem(int Index, Character* Player, , int ItemCount)
{
	//Player->Remove
}
