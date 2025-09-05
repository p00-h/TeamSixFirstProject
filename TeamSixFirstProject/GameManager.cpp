#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "Golem.h"
#include "Imp.h"
#include "Kobold.h"

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
    const char* items[] = { "게임 시작하기", "종료" };
    const int count = 2;
    int sel = 0;

    while (true) {
        ClearScreen();
        ShowTitle(); // 타이틀 아트 출력
        cout << "\n==== 메뉴 ====\n\n";

        for (int i = 0; i < count; ++i) {
            if (i == sel) cout << "> " << items[i] << " <\n";
            else          cout << "  " << items[i] << "\n";
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

    switch (RandRange(0, 2)) {
    case 0: monster = new Golem(level); break;
    case 1: monster = new Imp(level);    break;
    case 2: monster = new Kobold(level); break;
    }

    const int hp = RandRange(level * 20, level * 30);
    const int atk = RandRange(level * 5, level * 10);
    monster->SetHP(hp);
    monster->SetAttack(atk);
    return monster;
}
    

// 새 게임 시작
void GameManager::StartNewGame() {
    ClearScreen();
    cout << "[TEXT RPG 시작]\n";
	std::cout << "* 닉네임을 입력해주세요: ";
    std::string name;
    std::cin >> name;

    Character* player = new Character(name);
    
    bool keepPlaying = true;
    while (keepPlaying && player->GetHp() > 0) {
        bool isLive = false;
        // 베틀
        GameManager gameManager;

	    Monster* monster = gameManager.CreateMonster(player->GetLevel());

        cout << "몬스터가 생성되었습니다! 이름: " << monster->GetName()
             << ", HP: " << monster->GetHP()
		    << ", Attack: " << monster->GetAttack() << "\n";
    
        //결과 처리
        if (isLive) {
            player->AddExp(50);
            player->AddGold(RandRange(10,20));
            player->ShowStatus();
        }else{
			cout << "플레이어가 패배했습니다...\n";
        }
        break;
    
        player->ShowStatus();
		delete monster;
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
            cout << "\n게임을 종료합니다.\n";
            break;
        }
    }
}