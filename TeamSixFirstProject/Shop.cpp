//#include <map>
#include <vector>
#include <utility>
#include <iostream>
#include <conio.h>
#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include "AttackBoost.h"
#include "DefenseBoost.h"
#include "HealthPotion.h"
#include "ManaPotion.h"

using namespace std;

Shop::Shop()
{
    AvailableItems.push_back({ new AttackBoost(), 3 });
    AvailableItems.push_back({ new DefenseBoost(), 3 });
    AvailableItems.push_back({ new HealthPotion(), 3 });
    AvailableItems.push_back({ new ManaPotion(), 3 });


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


void Shop::VisitShop(Character* character)
{

    ShowShopMenu(character);

}

void Shop::ShowShopMenu(Character* character)
{
    int selected = 0;
    string ShopOptions[3] = { "������ ����", "������ �Ǹ�", "���� ������" };

    while (true) 
    {
        system("cls");
        cout << "===== ���� =====\n";
        for (int i = 0; i < 3; i++) {
            if (i == selected) cout << "> " << ShopOptions[i] << endl;
            else cout << "  " << ShopOptions[i] << endl;
        }

        int key = _getch();
        if (key == 224) 
        {
            key = _getch();
            if (key == 72 && selected > 0) selected--; // ��
            if (key == 80 && selected < 2) selected++; // ��
        }
        else if (key == 13) 
        { // ����
            if (ShopOptions[selected] == "������ ����") {
                ShowBuyMenu(character); // ������ ���� �޴� ���� �Լ��� �и�
            }
            else if (ShopOptions[selected] == "������ �Ǹ�") {
                // �Ǹ� �޴� �Լ�
                // ShowSellMenu();
            }
            else if (ShopOptions[selected] == "���� ������") {
                break; // ���� ������
            }
        }
    }
}

void Shop::ShowBuyMenu(Character* character)
{
    int itemSelected = 0;

    while (true) 
    {
        system("cls");
        cout << "===== ������ ���� =====\n";
        for (int i = 0; i < AvailableItems.size(); i++) 
        {
            string name = AvailableItems[i].first->GetName();
            if (i == itemSelected) cout << "> " << name << endl;
            else cout << "  " << name << endl;
        }
        cout << "ESC: ���� �޴��� ���ư���\n";

        int key = _getch();
        if (key == 224) 
        {
            key = _getch();
            if (key == 72 && itemSelected > 0) itemSelected--; // ��
            if (key == 80 && itemSelected < AvailableItems.size() - 1) itemSelected++; // ��
        }
        else if (key == 13) 
        {
           // cout << AvailableItems[itemSelected].first->GetName() << " ����!\n";
            //_getch(); // ��� ����

            BuyItem(AvailableItems[itemSelected], character);
        }
        else if (key == 27) 
        { // ESC
            break; // ������ ���� �޴� ����
        }
    }
}


void Shop::DisplayItems()
{
    cout << "===== ���� =====" << endl;
    int i = 1;
    for (auto& it : AvailableItems)
    {
        cout << it.first->GetName() << " " << it.second << "��" << endl; //<< it.first->;
        ++i;
    }
}


void Shop::BuyItem(pair<Item*, int>& item, Character* character)
{
    Item* buyItem = item.first;

    if (item.second <= 0)
    {
        cout << buyItem->GetName() << "�� ��� �����մϴ�.";

        return;
    }


    if (character->SpendGold(buyItem->GetPrice()))
    {
        character->AddItem(buyItem);

        item.second--; 

        cout << buyItem->GetName() << "��(��) �����߽��ϴ�.";
    }

    

}


//void Shop::SellItem(int Index, Character* Player, int ItemCount)
//{
//	Item* buyItem = AvailableItems[Index - 1].first;
//
//	if (Player->RemoveItem(ItemCount))
//	{
//
//	}
//}
