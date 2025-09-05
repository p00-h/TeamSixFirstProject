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
    

// �� ���� ����
void GameManager::StartNewGame() {
    ClearScreen();
    cout << "[TEXT RPG ����]\n";
	cout << "* �г����� �Է����ּ���: ";
    string name;
    cin >> name;

    Character player(name);
    
    bool keepPlaying = true;
    while (keepPlaying && player.GetHp() > 0) {
        // ��Ʋ
        GameManager gameManager;

        Monster* monster = gameManager.CreateMonster(player.GetLevel());

        cout << "���Ͱ� �����Ǿ����ϴ�! �̸�: " << monster->GetName()
            << ", HP: " << monster->GetHP()
            << ", Attack: " << monster->GetAttack() << "\n";

		Battle battle;
        //int isLive = battle.StartBattle(&player, monster);
        int isLive = 0;
        //��� ó��
        if (isLive) {
            player.SetExp(player.GetExp() + 50);
            player.AddGold(RandRange(10, 20));
			//������
			bool isLevelUp = false;
            if(player.GetExp() >= 100) {
                player.SetExp(0);
                player.SetLevel(player.GetLevel() + 1);
				isLevelUp = true;
            }
            player.ShowStatus();
            if(isLevelUp)
                cout << "�÷��̾ �¸��߽��ϴ�!\n";
			cout << "�÷��̾ �¸��߽��ϴ�!\n";
            //�����


            // ���� �湮 ���� ����
            while (true) {
                std::cout << "\n������ �湮 �Ͻðڽ��ϱ�? (Y / N)\n> ";
                std::string choice; std::cin >> choice;
                if (choice.empty()) continue;
                char c = (char)std::toupper((unsigned char)choice[0]);
                if (c == 'Y') {
                    openShop(player);    // ���� ���ٰ�
                    ClearScreen();       //    ���͵� while ���
                    break;
                }
                else if (c == 'N') {
                    ClearScreen();
                    break;
                }
                else {
                    std::cout << "Y/N �߿��� �����ϼ���.\n";
                }
            }

            continue;

        }else if(isLive == 2){
            ClearScreen();
            player.ShowStatus();
            cout << "�÷��̾ �����ƽ��ϴ�...\n";
        }
        else {
            ClearScreen();
            player.ShowStatus();
			cout << "�÷��̾ �й��߽��ϴ�...\n";
        }
    
		delete monster;
        break;
    }
    

	

    // Battle Battle;

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