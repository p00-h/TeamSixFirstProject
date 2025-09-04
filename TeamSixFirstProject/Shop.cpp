#include "Shop.h"
#include "Item.h"
#include "Player.h"
//#include <vector>
#include <map>;
#include <iostream>
using namespace std;

Shop::Shop()
{
	//AvailableItems.push_back();

	cout << "상점에 오신 걸 환영합니다!" << endl;
}

void Shop::DisplayItems()
{
	cout << "구매 가능한 아이템" << endl;

	for (auto it = AvailableItems)
	{
		cout << it.GetName() << ": " << it.GetPrice();
	}

	for (iter = AvailableItems.begin(); iter != AvailableItems.end(); iter++)
	{
		cout << iter->first << "\n";
		cout << iter->second << "\n";
	}
}

void Shop::BuyItem(int Index, Character* Player)
{
	int playerGold = Player->GetGold();
	int buyItem = AvailableItems[Index];

	if (PlayerGold < buyItem.GetGold())
	{
		cout << "돈이 부족합니다." << endl;
	}
	else
	{
		//Player->Inventory.Push_back(AvailableItems[Index]);
		//Player->AddItem(AvailableItems[Index]);

		Player->SetGold(playerGold - buyItem.GetGold());

		cout << buyItem.GetName() << "을 구매했습니다!"
	}
}

void Shop::SellItem(int Index, Character* Player)
{
	map<Item*, int> PlayerInventory = Player->GetInventory();

	PlayerInventory.begin();

	PlayerInventory-

	//Player->sellitem(Index, 1);
}
