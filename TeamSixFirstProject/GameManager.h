#pragma once
#include "Title.h"
#include "Monster.h"
#include "Character.h"

#include <vector>
#include <string>

class GameManager {
public:
    GameManager();
    void Run();

private:
    void ClearScreen();
    void WaitForEnter();

    int  ShowMenu();        //타이틀 ↑↓ 선택 + Enter 확정
    void StartNewGame();
	Monster* CreateMonster(int level);
    void openShop(Character& player);
    // 행동 선택 메뉴
    int ArrowMenu(const std::vector<std::string>& items, const Character& player, const char* title);
};
