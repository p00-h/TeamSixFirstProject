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

	cout << "������ ���� �� ȯ���մϴ�!" << endl;
}

void Shop::DisplayItems()
{
	cout << "���� ������ ������" << endl;

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
		cout << "���� �����մϴ�." << endl;
	}
	else
	{
		//Player->Inventory.Push_back(AvailableItems[Index]);
		//Player->AddItem(AvailableItems[Index]);

		Player->SetGold(playerGold - buyItem.GetGold());

		cout << buyItem.GetName() << "�� �����߽��ϴ�!"
	}
}

void Shop::SellItem(int Index, Character* Player)
{
	map<Item*, int> PlayerInventory = Player->GetInventory();

	PlayerInventory.begin();

	PlayerInventory-

	//Player->sellitem(Index, 1);
}
