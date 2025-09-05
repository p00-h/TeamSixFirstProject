#pragma once
#include "Title.h"
#include "Monster.h"
#include "Character.h"

class GameManager {
public:
    GameManager();
    void Run();

private:
    void ClearScreen();
    void WaitForEnter();

    int  ShowMenu();        // ↑↓ 선택 + Enter 확정
    void StartNewGame();
	Monster* CreateMonster(int level);
    void openShop(Character& player);
};
