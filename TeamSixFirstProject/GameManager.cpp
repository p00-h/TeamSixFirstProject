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

// lo~hi 사이의 랜덤 정수 반환
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
    system("pause");  // "Press any key to continue . . ." 메시지 출력
}


// 화살표 ↑↓로 이동하고 Enter로 확정하는 메뉴
int GameManager::ShowMenu() {
    const char* items[] = { "게임 시작하기", "    게임 종료" };
    const int count = 2;
    int sel = 0;

    while (true) {
        ClearScreen();
        ShowTitle(); // 타이틀 아트 출력

        for (int i = 0; i < count; ++i) {
            if (i == sel) cout << "                                           -> " << items[i] << "\n";
            else          cout << "                                              " << items[i] << "\n";
        }

        int key = _getch();
        if (key == 224) {        // 방향키 prefix
            key = _getch();
            if (key == 72) {     // ↑
                sel = (sel - 1 + count) % count;
            }
            else if (key == 80) { // ↓
                sel = (sel + 1) % count;
            }
        }
        else if (key == 13) {  // Enter
            return (sel == 0) ? 1 : 2; // 1=시작, 2=종료
        }
        else if (key == 27) {  // ESC -> 종료
            return 2;
        }
    }
}

// level에 따라 몬스터 생성
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

void GameManager::OpenShop(Character& player)
{
    Shop shop;
    shop.VisitShop(&player);
}

int GameManager::ArrowMenu(const std::vector<std::string>& items, const Character& player)
{
    int sel = 0;
    const int n = static_cast<int>(items.size());

    while (true) {
        ClearScreen();

        // 상태/인벤토리 고정 표시
        player.ShowStatus();
        std::cout << "\n";
        player.ShowInventory();
        std::cout << "\n";

        // 메뉴 렌더링
        std::cout << "========================\n";
        for (int i = 0; i < n; ++i) {
            if (i == sel) std::cout << "                 -> " << items[i] << "\n";
            else          std::cout << "                    " << items[i] << "\n";
        }

        // 입력 처리
        int key = _getch();
        if (key == 224) {           // 방향키 prefix
            key = _getch();
            if (key == 72) {        // ↑
                sel = (sel - 1 + n) % n;
            }
            else if (key == 80) { // ↓
                sel = (sel + 1) % n;
            }
        }
        else if (key == 13) {     // Enter
            return sel;
        }
        else if (key == 27) {     // ESC -> 마지막 항목(나가기)로 취급
            return n - 1;
        }
    }
}
    

// 새 게임 시작
void GameManager::StartNewGame() {
    ShowGameRules();
	WaitForEnter();
    ClearScreen();
    std::cout << "[TEXT RPG 시작]\n";
    std::cout << "* 닉네임을 입력해주세요: ";
    std::string name;
    std::cin >> name;

    Character player(name);

    bool keepPlaying = true;
    bool didBattleOnce = false;

    while (keepPlaying && player.GetHp() > 0) {
        // 메뉴 구성: 첫 전투 전 / 이후 분기
        int sel = 0;
        if (!didBattleOnce) {
            sel = ArrowMenu({ "전투", "종료" }, player);
            if (sel == 1) break; // 나가기
        }
        else {
            sel = ArrowMenu({ "전투", "상점", "종료" }, player);
            if (sel == 2) break; // 나가기
            if (sel == 1) {      // 상점
                OpenShop(player);
                continue;
            }
            // sel == 0 -> 전투
        }

        // ===== 전투 시작 =====
        GameManager gm; 
        Monster* monster = gm.CreateMonster(player.GetLevel());

        std::cout << "몬스터가 생성되었습니다! 이름: " << monster->GetName()
            << ", HP: " << monster->GetHP()
            << ", Attack: " << monster->GetAttack() << "\n";

        Battle battle;
        int isLive = battle.StartBattle(&player, monster); // 실제 전투 함수로 교체
        //int isLive = 1; // 임시: 승리(1), 도망(2), 패배(0)

        // ===== 전투 결과 처리 =====
        if (isLive == 1) { // 승리
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
            std::cout << "플레이어가 승리했습니다! " << (isLevelUp ? "레벨 업! \n" : "\n");

            // 드랍템 (30%)
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
                std::cout << "\n[전리품 획득]\n";
                player.ShowInventory();
            }
            WaitForEnter();      
            ClearScreen();       
        }
        else if (isLive == 2) { // 도망
            ClearScreen();
            player.ShowStatus();
            std::cout << "플레이어가 도망쳤습니다...\n";
            WaitForEnter();      
            ClearScreen();       
            didBattleOnce = true; 
        }
        else { // 패배
            ClearScreen();
            player.ShowStatus();
            std::cout << "플레이어가 패배했습니다...\n";
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
            cout << "\n게임을 종료합니다.\n";
            break;
        }
    }
}

void GameManager::ShowGameRules() {
    cout << "[게임 규칙 안내]\n";
    cout << "* 플레이어는 전투를 통해 경험치를 얻고 레벨을 올릴 수 있습니다.\n";
    cout << "* 15레벨에 도달하면 강력한 보스 몬스터 [드래곤]이 등장합니다.\n";
    cout << "* 드래곤과의 결투에서 승리하면 게임은 엔딩을 맞이하게 됩니다.\n";
    cout << "* 전투 중 행동은 3가지 중 하나를 선택할 수 있습니다.\n";
    cout << "    - 공격: 몬스터에게 직접 공격을 가합니다.\n";
    cout << "    - 아이템 사용: 인벤토리에서 아이템을 사용합니다.\n";
    cout << "    - 도망가기: 전투에서 도망칠 수 있습니다.\n";
    cout << "* 상점은 전투를 최소 1회 이상 진행해야 활성화됩니다.\n";
    cout << "* 상점에서는 아이템 구매 및 판매가 가능합니다.\n";
    cout << "    - 구매: 골드를 소모해 아이템을 획득합니다.\n";
    cout << "    - 판매: 아이템을 판매하고 상점 구매가의 절반만큼의 골드를 획득합니다.\n\n";
	cout << "게임을 시작하려면 엔터 키를 눌러주세요...\n";
}