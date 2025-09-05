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

    int  ShowMenu();        //Ÿ��Ʋ ��� ���� + Enter Ȯ��
    void StartNewGame();
	Monster* CreateMonster(int level);
    void openShop(Character& player);
    // �ൿ ���� �޴�
    int ArrowMenu(const std::vector<std::string>& items, const Character& player, const char* title);
};
