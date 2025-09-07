#include <map>
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
    ResetItem();
}

Shop::~Shop()
{
    for (auto& it : AvailableItems)
    {
        delete it.first;
    }
    AvailableItems.clear();
}


void Shop::ResetItem()
{
    AvailableItems.push_back({ new AttackBoost(), 3 });
    AvailableItems.push_back({ new DefenseBoost(), 3 });
    AvailableItems.push_back({ new HealthPotion(), 3 });
    AvailableItems.push_back({ new ManaPotion(), 3 });
}


void Shop::VisitShop(Character* character)
{
    cout << "������ ���� �� ȯ���մϴ�!" << endl;

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
                ShowBuyMenu(character); 
            }
            else if (ShopOptions[selected] == "������ �Ǹ�") {
                // �Ǹ� �޴� �Լ�
               ShowSellMenu(character);
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
            string info = AvailableItems[i].first->ItemInfo();
            int price = AvailableItems[i].first->GetPrice();
           if (i == itemSelected) cout << "> " << name << "(" << info << ")"  << " ���:" << AvailableItems[i].second << " " << price << "G " << endl;
           else cout << "  " << name << "(" << info << ")" << " ���:" << AvailableItems[i].second << " " << price << "G " << endl;

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
           

            BuyItem(AvailableItems[itemSelected], character);

            _getch(); // ��� ����
        }
        else if (key == 27) 
        { // ESC
            break; // ������ ���� �޴� ����
        }
    }
}

void Shop::ShowSellMenu(Character* character)
{
    int itemSelected = 0;

  

    while (true)
    {
        map<string, pair<Item*, int>> InventoryMap = character->GetInventory();

        vector<pair<Item*, int>> Inventory;

        for (auto& it : InventoryMap)
        {
            Inventory.push_back(it.second);
        }

        if (Inventory.empty())
        {
            cout << "�κ��丮�� ����ֽ��ϴ�." << endl;

            _getch();

            return;
        }


        system("cls");
        cout << "===== ������ �Ǹ� =====" << endl;
        /* for (int i = 0; i < Inventory.size(); i++)
         {

             if (i == itemSelected) cout << "> " << Inventory[0].first << endl;
             else cout << "  " << endl;
         }*/


      
        for (int i =0; i < Inventory.size(); i++)
        {
            string itemName = Inventory[i].first->GetName();
            int itemCount = Inventory[i].second;             

           if(i == itemSelected) cout << "> " << itemName << " : " << itemCount << endl;
           else  cout << "  " << itemName << " : " << itemCount << endl;
        }

        cout << "ESC: ���� �޴��� ���ư���\n";

        int key = _getch();
        if (key == 224)
        {
            key = _getch();
            if (key == 72 && itemSelected > 0) itemSelected--; // ��
            if (key == 80 && itemSelected < Inventory.size() - 1) itemSelected++; // ��
        }
        else if (key == 13)
        {
            // cout << AvailableItems[itemSelected].first->GetName() << " ����!\n";

            SellItem(Inventory[itemSelected], character);

            _getch(); // ��� ����
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
    Item* buyItem = item.first->Clone();

    if (item.second <= 0)
    {
        cout << buyItem->GetName() << "�� ��� �����մϴ�.";

        return;
    }

    if (character->SpendGold(buyItem->GetPrice()))
    {
        cout << buyItem->GetName() << "��(��) �����߽��ϴ�." << endl;

        character->AddItem(buyItem,1);

        item.second--; 

        
    }
}

void Shop::SellItem(pair<Item*, int> item, Character* character)
{
    string name = item.first->GetName();
    

    character->SellItem(name, 1, SellRatio);

}

