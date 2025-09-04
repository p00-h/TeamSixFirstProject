#include "GameManager.h"
#include <iostream>
#include <limits>
#include <conio.h>   // _getch()

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

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

void GameManager::StartNewGame() {
    ClearScreen();
    cout << "[TEXT RPG 시작]\n";

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
