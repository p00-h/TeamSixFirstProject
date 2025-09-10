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

    void SetColor(int color);
    void SetColorDefault();

private:
    void ClearScreen();
    void WaitForEnter();
	void ShowGameRules();

    bool SaveToFile(const Character& player, const std::string& path = "save.txt");
    bool LoadFromFile(Character& player, const std::string& path = "save.txt");
    void PlayLoop(Character& player); // ÀüÅõ/»óÁ¡ ¸ÞÀÎ ·çÇÁ ºÐ¸®

    int  ShowMenu();        //Å¸ÀÌÆ² ¡è¡é ¼±ÅÃ + Enter È®Á¤
    // Çàµ¿ ¼±ÅÃ ¸Þ´º
    int ArrowMenu(const std::vector<std::string>& items, const Character& player);

    void StartNewGame();


	Monster* CreateMonster(int level);
    void OpenShop(Character& player);
};

	Monster* CreateMonster(int level);
};

