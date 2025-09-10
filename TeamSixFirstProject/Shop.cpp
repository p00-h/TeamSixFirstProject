#include <map>
#include <vector>
#include <utility>
#include <iostream>
#include <conio.h>
#include <iomanip> //setw
#include <Windows.h>
#include <mmsystem.h>


#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include "AttackBoost.h"
#include "DefenseBoost.h"
#include "HealthPotion.h"
#include "ManaPotion.h"

#pragma comment(lib,"winmm.lib")


using namespace std;

Shop::Shop()
{ 
    ResetItem();
}

Shop::~Shop()
{
    DeleteShopItem();
}

void Shop::DeleteShopItem()
{
    for (auto& it : AvailableItems)
    {
        delete it.first;
    }
    AvailableItems.clear();
}

void Shop::ResetItem()
{
    DeleteShopItem();

    AvailableItems.push_back({ new AttackBoost(), 3 });
    AvailableItems.push_back({ new DefenseBoost(), 3 });
    AvailableItems.push_back({ new HealthPotion(), 3 });
    AvailableItems.push_back({ new ManaPotion(), 3 });
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
        cout << "============= [����] =============" << endl;
        cout << "���� ����: ������ �°� ȯ���ϳ�!\n           ���� �ʿ�����? \n";
        cout << "----------------------------------" << endl;
        SetColor(14); // yellow
        cout << "���� ���:" << character->GetGold() << "G \n";
        SetColorDefault();
        cout << "----------------------------------" << endl;

        for (int i = 0; i < 3; i++)
        {
            if (i == selected)
            {
                SetColor(15); // white
                cout << "> " << ShopOptions[i] << endl;
                SetColorDefault();
            }
            else
            {
                SetColor(8); // dark gray
                cout << "  " << ShopOptions[i] << endl;
                SetColorDefault();
            }
                
        }

        cout << "==================================" << endl;
        
        

        int key = _getch();
        if (key == 224) 
        {
            key = _getch();
            if (key == 72 && selected > 0)
            {
                PlaySound(TEXT("Cursor2.wav"), NULL, SND_FILENAME | SND_ASYNC);
                selected--; // ��
            }
             
            if (key == 80 && selected < 2)
            {
                PlaySound(TEXT("Cursor2.wav"), NULL, SND_FILENAME | SND_ASYNC);
                selected++; // ��
            }
        }
        else if (key == 13) 
        { // ����
            if (ShopOptions[selected] == "������ ����") {
               
                ShowBuyMenu(character); 
            }
            else if (ShopOptions[selected] == "������ �Ǹ�") {
              
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
        cout << "============= [������ ����] =============" << endl;
        cout << "       �����۸�       ���      ���� \n";
        cout << "-----------------------------------------" << endl;
        //setw(10);
        
        ShowShopUI(AvailableItems, itemSelected, character);

        int key = _getch();
        if (key == 224) 
        {
            key = _getch();
            if (key == 72 && itemSelected > 0)
            {
                PlaySound(TEXT("Cursor2.wav"), NULL, SND_FILENAME | SND_ASYNC);
                itemSelected--; // ��
            }
            if (key == 80 && itemSelected < AvailableItems.size() - 1)
            {
                PlaySound(TEXT("Cursor2.wav"), NULL, SND_FILENAME | SND_ASYNC);
                itemSelected++; // ��
            }
        }
        else if (key == 13) 
        {
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

        if (Inventory.size() <= itemSelected)
        {
            itemSelected = 0;
        }


        system("cls");
        cout << "============= [������ �Ǹ�] =============" << endl;
        cout << "       �����۸�       ����      ���� \n";
        cout << "-----------------------------------------" << endl;

        ShowShopUI(Inventory, itemSelected, character, SellRatio);

        int key = _getch();
        if (key == 224)
        {
            key = _getch();
            if (key == 72 && itemSelected > 0)
            {
                PlaySound(TEXT("Cursor2.wav"), NULL, SND_FILENAME | SND_ASYNC);
                itemSelected--;
            }
            // ��
            if (key == 80 && itemSelected < Inventory.size() - 1)
            {
                PlaySound(TEXT("Cursor2.wav"), NULL, SND_FILENAME | SND_ASYNC);
                itemSelected++;
            } // ��
        }
        else if (key == 13)
        {
            SellItem(Inventory[itemSelected], character);

            _getch(); // ��� ����
        }
        else if (key == 27)
        { // ESC
            break; // ������ ���� �޴� ����
        }
    }

}

void Shop::ShowShopUI(vector<pair<Item*, int>> items, int selectnum,  Character* character, float priceratio)
{
    for (int i = 0; i < items.size(); i++)
    {
        string name = items[i].first->GetName();
        string info = items[i].first->ItemInfo();
        int price = items[i].first->GetPrice() * priceratio;
        int count = items[i].second;

        int space = (name.size());

        if (i == selectnum)
        {
            SetColor(15); // white
            cout << "> " << name << setw(22 - space) << "x" << count << setw(10) << price << "G " << endl;
            SetColorDefault(); // gray
        }
        else
        {
            SetColor(8); // dark gray
            cout << "  " << name << setw(22 - space) << "x" << count << setw(10) << price << "G " << endl;
            SetColorDefault();
        }

    }
    cout << "-----------------------------------------" << endl;
    SetColor(15); //
    cout << "[ȿ��] " << items[selectnum].first->ItemInfo() << endl;
    //SetColorDefault();
    SetColor(14); // yellow
    cout << "���� ���:" << character->GetGold() << "G \n";
    SetColorDefault();
    cout << "-----------------------------------------" << endl;

    SetColor(12); // red
    cout << "ESC: ���� �޴��� ���ư���\n";
    SetColorDefault();
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

        PlaySound(TEXT("Shop.wav"), NULL, SND_FILENAME | SND_ASYNC); //�Ϲ� ���
        character->AddItem(buyItem,1);

        item.second--; 

        
    }
}

void Shop::SellItem(pair<Item*, int> item, Character* character)
{
    string name = item.first->GetName();
    
    PlaySound(TEXT("Shop.wav"), NULL, SND_FILENAME | SND_ASYNC); //�Ϲ� ���

    character->SellItem(name, 1, SellRatio);

}


void Shop::SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Shop::SetColorDefault()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}






