#pragma once
#include "Title.h"
#include "Monster.h"

class GameManager {
public:
    GameManager();
    void Run();

private:
    void ClearScreen();
    void WaitForEnter();

    int  ShowMenu();        // ��� ���� + Enter Ȯ��
    void StartNewGame();
	Monster* CreateMonster(int level);
};
