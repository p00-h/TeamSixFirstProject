#pragma once
#include "Title.h"
#include "Monster.h"
<<<<<<< HEAD
=======
#include "Character.h"

#include <vector>
#include <string>
>>>>>>> parent of 5e63b35 (Merge branch 'main' into dev)

class GameManager {
public:
    GameManager();
    void Run();

private:
    void ClearScreen();
    void WaitForEnter();
<<<<<<< HEAD
=======
	void ShowGameRules();

    bool SaveToFile(const Character& player, const std::string& path = "save.txt");
    bool LoadFromFile(Character& player, const std::string& path = "save.txt");
    void PlayLoop(Character& player); // ����/���� ���� ���� �и�

    int  ShowMenu();        //Ÿ��Ʋ ��� ���� + Enter Ȯ��
    // �ൿ ���� �޴�
    int ArrowMenu(const std::vector<std::string>& items, const Character& player);
>>>>>>> parent of 5e63b35 (Merge branch 'main' into dev)

    int  ShowMenu();        // ��� ���� + Enter Ȯ��
    void StartNewGame();
<<<<<<< HEAD
	Monster* CreateMonster(int level);
};
=======

	Monster* CreateMonster(int level);
    void OpenShop(Character& player);
};
>>>>>>> parent of 5e63b35 (Merge branch 'main' into dev)
