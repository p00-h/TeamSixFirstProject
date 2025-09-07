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
    cout << "상점에 오신 걸 환영합니다!" << endl;

    ShowShopMenu(character);

}

void Shop::ShowShopMenu(Character* character)
{
    int selected = 0;
    string ShopOptions[3] = { "아이템 구매", "아이템 판매", "상점 나가기" };

    while (true) 
    {
        system("cls");
        cout << "===== 상점 =====\n";
        for (int i = 0; i < 3; i++) {
            if (i == selected) cout << "> " << ShopOptions[i] << endl;
            else cout << "  " << ShopOptions[i] << endl;
        }

        int key = _getch();
        if (key == 224) 
        {
            key = _getch();
            if (key == 72 && selected > 0) selected--; // ↑
            if (key == 80 && selected < 2) selected++; // ↓
        }
        else if (key == 13) 
        { // 엔터
            if (ShopOptions[selected] == "아이템 구매") {
                ShowBuyMenu(character); 
            }
            else if (ShopOptions[selected] == "아이템 판매") {
                // 판매 메뉴 함수
               ShowSellMenu(character);
            }
            else if (ShopOptions[selected] == "상점 나가기") {
                break; // 상점 나가기
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
        cout << "===== 아이템 구매 =====\n";
        for (int i = 0; i < AvailableItems.size(); i++) 
        {
            string name = AvailableItems[i].first->GetName();
            string info = AvailableItems[i].first->ItemInfo();
            int price = AvailableItems[i].first->GetPrice();
           if (i == itemSelected) cout << "> " << name << "(" << info << ")"  << " 재고:" << AvailableItems[i].second << " " << price << "G " << endl;
           else cout << "  " << name << "(" << info << ")" << " 재고:" << AvailableItems[i].second << " " << price << "G " << endl;

        }
        cout << "ESC: 상점 메뉴로 돌아가기\n";

        int key = _getch();
        if (key == 224) 
        {
            key = _getch();
            if (key == 72 && itemSelected > 0) itemSelected--; // ↑
            if (key == 80 && itemSelected < AvailableItems.size() - 1) itemSelected++; // ↓
        }
        else if (key == 13) 
        {
           // cout << AvailableItems[itemSelected].first->GetName() << " 구매!\n";
           

            BuyItem(AvailableItems[itemSelected], character);

            _getch(); // 잠깐 멈춤
        }
        else if (key == 27) 
        { // ESC
            break; // 아이템 구매 메뉴 종료
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
            cout << "인벤토리가 비어있습니다." << endl;

            _getch();

            return;
        }


        system("cls");
        cout << "===== 아이템 판매 =====" << endl;
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

        cout << "ESC: 상점 메뉴로 돌아가기\n";

        int key = _getch();
        if (key == 224)
        {
            key = _getch();
            if (key == 72 && itemSelected > 0) itemSelected--; // ↑
            if (key == 80 && itemSelected < Inventory.size() - 1) itemSelected++; // ↓
        }
        else if (key == 13)
        {
            // cout << AvailableItems[itemSelected].first->GetName() << " 구매!\n";

            SellItem(Inventory[itemSelected], character);

            _getch(); // 잠깐 멈춤
        }
        else if (key == 27)
        { // ESC
            break; // 아이템 구매 메뉴 종료
        }
    }

}



void Shop::DisplayItems()
{
    cout << "===== 상점 =====" << endl;
    int i = 1;
    for (auto& it : AvailableItems)
    {
        cout << it.first->GetName() << " " << it.second << "개" << endl; //<< it.first->;
        ++i;
    }
}



void Shop::BuyItem(pair<Item*, int>& item, Character* character)
{
    Item* buyItem = item.first->Clone();

    if (item.second <= 0)
    {
        cout << buyItem->GetName() << "의 재고가 부족합니다.";

        return;
    }

    if (character->SpendGold(buyItem->GetPrice()))
    {
        cout << buyItem->GetName() << "을(를) 구매했습니다." << endl;

        character->AddItem(buyItem,1);

        item.second--; 

        
    }
}

void Shop::SellItem(pair<Item*, int> item, Character* character)
{
    string name = item.first->GetName();
    

    character->SellItem(name, 1, SellRatio);

}

