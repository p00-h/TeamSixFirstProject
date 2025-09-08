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
	void ShowGameRules();

    bool SaveToFile(const Character& player, const std::string& path = "save.txt");
    bool LoadFromFile(Character& player, const std::string& path = "save.txt");
    void PlayLoop(Character& player); // ����/���� ���� ������ �и�

    int  ShowMenu();        //Ÿ��Ʋ ��� ���� + Enter Ȯ��
    // �ൿ ���� �޴�
    int ArrowMenu(const std::vector<std::string>& items, const Character& player);

    void StartNewGame();

	Monster* CreateMonster(int level);
    void OpenShop(Character& player);
};