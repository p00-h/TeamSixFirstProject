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

void GameManager::StartNewGame() {
    ClearScreen();
    cout << "[TEXT RPG ����]\n";

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
