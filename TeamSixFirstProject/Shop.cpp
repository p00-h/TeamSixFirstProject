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


void Shop::VisitShop(Character* character)
{

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
                ShowBuyMenu(character); // 아이템 구매 메뉴 따로 함수로 분리
            }
            else if (ShopOptions[selected] == "아이템 판매") {
                // 판매 메뉴 함수
                // ShowSellMenu();
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
            if (i == itemSelected) cout << "> " << name << endl;
            else cout << "  " << name << endl;
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
            //_getch(); // 잠깐 멈춤

            BuyItem(AvailableItems[itemSelected], character);
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
    Item* buyItem = item.first;

    if (item.second <= 0)
    {
        cout << buyItem->GetName() << "의 재고가 부족합니다.";

        return;
    }


    if (character->SpendGold(buyItem->GetPrice()))
    {
        character->AddItem(buyItem);

        item.second--; 

        cout << buyItem->GetName() << "을(를) 구매했습니다.";
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
