#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "Golem.h"
#include "Imp.h"
#include "Orc.h"
#include "Slime.h"
#include "Kobold.h"
#include "Battle.h"
#include "Shop.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "DefenseBoost.h"
#include "ManaPotion.h"


#include <iostream>
#include <limits>
#include <conio.h>   // _getch()

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// lo~hi ������ ���� ���� ��ȯ
static int RandRange(int lo, int hi) {
    return lo + std::rand() % (hi - lo + 1);
}

GameManager::GameManager() {}

void GameManager::ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void GameManager::WaitForEnter() {
    system("pause");  // "Press any key to continue . . ." �޽��� ���
}


// ȭ��ǥ ���� �̵��ϰ� Enter�� Ȯ���ϴ� �޴�
int GameManager::ShowMenu() {
    const char* items[] = { "���� �����ϱ�", "����" };
    const int count = 2;
    int sel = 0;

    while (true) {
        ClearScreen();
        ShowTitle(); // Ÿ��Ʋ ��Ʈ ���
        cout << "\n==== �޴� ====\n\n";

        for (int i = 0; i < count; ++i) {
            if (i == sel) cout << "> " << items[i] << " <\n";
            else          cout << "  " << items[i] << "\n";
        }

        int key = _getch();
        if (key == 224) {        // ����Ű prefix
            key = _getch();
            if (key == 72) {     // ��
                sel = (sel - 1 + count) % count;
            }
            else if (key == 80) { // ��
                sel = (sel + 1) % count;
            }
        }
        else if (key == 13) {  // Enter
            return (sel == 0) ? 1 : 2; // 1=����, 2=����
        }
        else if (key == 27) {  // ESC -> ����
            return 2;
        }
    }
}

// level�� ���� ���� ����
Monster* GameManager::CreateMonster(int level)
{
	Monster* monster = nullptr;

    switch (RandRange(0, 4)) {
    case 0: monster = new Golem(level); break;
    case 1: monster = new Imp(level);    break;
    case 2: monster = new Kobold(level); break;
    case 3: monster = new Orc(level); break;
    case 4: monster = new Slime(level); break;
    }

    const int hp = RandRange(level * 20, level * 30);
    const int atk = RandRange(level * 5, level * 10);
    monster->SetHP(hp);
    monster->SetAttack(atk);
    return monster;
}

void GameManager::openShop(Character& player)
{
    Shop shop;
    shop.VisitShop(&player);
}

int GameManager::ArrowMenu(const std::vector<std::string>& items, const Character& player, const char* title)
{
    int sel = 0;
    const int n = static_cast<int>(items.size());

    while (true) {
        ClearScreen();

        // ��� Ÿ��Ʋ(����)
        if (title && *title) {
            std::cout << "==== " << title << " ====\n\n";
        }

        // ����/�κ��丮 ���� ǥ��
        player.ShowStatus();
        std::cout << "\n";
        player.ShowInventory();
        std::cout << "\n";

        // �޴� ������
        std::cout << "---- ���� ----\n";
        for (int i = 0; i < n; ++i) {
            if (i == sel) std::cout << "> " << items[i] << " <\n";
            else          std::cout << "  " << items[i] << "\n";
        }

        // �Է� ó��
        int key = _getch();
        if (key == 224) {           // ����Ű prefix
            key = _getch();
            if (key == 72) {        // ��
                sel = (sel - 1 + n) % n;
            }
            else if (key == 80) { // ��
                sel = (sel + 1) % n;
            }
        }
        else if (key == 13) {     // Enter
            return sel;
        }
        else if (key == 27) {     // ESC -> ������ �׸�(������)�� ���
            return n - 1;
        }
    }
}
    

// �� ���� ����
void GameManager::StartNewGame() {
    ClearScreen();
    std::cout << "[TEXT RPG ����]\n";
    std::cout << "* �г����� �Է����ּ���: ";
    std::string name;
    std::cin >> name;

    Character player(name);

    bool keepPlaying = true;
    bool didBattleOnce = false;

    while (keepPlaying && player.GetHp() > 0) {
        // �޴� ����: ù ���� �� / ���� �б�
        int sel = 0;
        if (!didBattleOnce) {
            sel = ArrowMenu({ "���� ����", "Ÿ��Ʋ ȭ������ ������" }, player, "�ൿ ����");
            if (sel == 1) break; // ������
        }
        else {
            sel = ArrowMenu({ "����", "����", "Ÿ��Ʋ ȭ������ ������" }, player, "�ൿ ����");
            if (sel == 2) break; // ������
            if (sel == 1) {      // ����
                openShop(player);
                continue;
            }
            // sel == 0 -> ����
        }

        // ===== ���� ���� =====
        GameManager gm; 
        Monster* monster = gm.CreateMonster(player.GetLevel());

        std::cout << "���Ͱ� �����Ǿ����ϴ�! �̸�: " << monster->GetName()
            << ", HP: " << monster->GetHP()
            << ", Attack: " << monster->GetAttack() << "\n";

        Battle battle;
        int isLive = battle.StartBattle(&player, monster); // ���� ���� �Լ��� ��ü
        //int isLive = 1; // �ӽ�: �¸�(1), ����(2), �й�(0)

        // ===== ���� ��� ó�� =====
        if (isLive == 1) { // �¸�
            didBattleOnce = true;

            player.SetExp(player.GetExp() + 50);
            player.AddGold(RandRange(10, 20));

            bool isLevelUp = false;
            if (player.GetExp() >= 100) {
                player.SetExp(0);
                player.SetLevel(player.GetLevel() + 1);
                isLevelUp = true;
            }

            ClearScreen();
            player.ShowStatus();
            std::cout << "�÷��̾ �¸��߽��ϴ�! " << (isLevelUp ? "���� ��! \n" : "\n");

            // ����� (30%)
            if (RandRange(1, 100) <= 30) {
                int dropType = RandRange(1, 4);
                Item* dropped = nullptr;
                switch (dropType) {
                case 1: dropped = new HealthPotion();  break;
                case 2: dropped = new ManaPotion();    break;
                case 3: dropped = new AttackBoost();   break;
                case 4: dropped = new DefenseBoost();  break;
                }
                player.AddItem(dropped);
                std::cout << "\n[����ǰ ȹ��]\n";
                player.ShowInventory();
            }
            WaitForEnter();      
            ClearScreen();       
        }
        else if (isLive == 2) { // ����
            ClearScreen();
            player.ShowStatus();
            std::cout << "�÷��̾ �����ƽ��ϴ�...\n";
            WaitForEnter();      
            ClearScreen();       
            didBattleOnce = true; 
        }
        else { // �й�
            ClearScreen();
            player.ShowStatus();
            std::cout << "�÷��̾ �й��߽��ϴ�...\n";
            WaitForEnter();      
            ClearScreen();       
            keepPlaying = false;
        }

        delete monster; 
    }

    WaitForEnter();
}



void GameManager::Run() {
    while (true) {
        int choice = ShowMenu();
        if (choice == 1) {
            StartNewGame();
        }
        else { // 2
            cout << "\n������ �����մϴ�.\n";
            break;
        }
    }
}