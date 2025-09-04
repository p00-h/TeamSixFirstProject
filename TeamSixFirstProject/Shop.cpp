#include <map>
#include <vector>
#include <utility>
#include <iostream>
#include "Shop.h"
//#include "Player.h"
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


	cout << "������ ���� �� ȯ���մϴ�!" << endl;

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
	cout << "���� ������ ������:" << endl;
	int i = 1;
	for (auto& it : AvailableItems)
	{
		cout << i << ". " << it.first->GetName() << " " << it.second << "��" << endl; //<< it.first->;
		++i;
	}
}

void Shop::BuyItem(int Index, Character* Player)
{
	int playerGold = Player->GetGold();
	Item* buyItem = AvailableItems[Index - 1].first;

	if (PlayerGold < buyItem.GetPrice())
	{
		cout << "���� �����մϴ�." << endl;
	}
	else
	{
		//Player->Inventory.Push_back(buyItem);
		//Player->AddItem(buyItem);

		Player->SetGold(playerGold - buyItem.GetGold());

		cout << buyItem.GetName() << "�� �����߽��ϴ�!"
	}
}

//void Shop::SellItem(int Index, Character* Player)
//{
//	map<Item*, int> PlayerInventory = Player->GetInventory();
//
//	PlayerInventory.begin();
//
//	PlayerInventory-
//
//	//Player->sellitem(Index, 1);
//}
