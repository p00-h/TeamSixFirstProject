#pragma once
#include <string>

class Monster;

class GameManager {
public:
    //void Battle(Character* player);
    void Battle(std::string name);
private:
    Monster* GenerateMonster(int level);
};