#pragma once
#include <iostream>
#include <string>
#include <map>

class Character {
private:
    std::string Name;
    int Level;
    int Hp;
    int Mp;
    int Attack;
    int Defense;
    int Exp;
    int Gold;
    const int ExpToLevelUp = 100;

    std::map<std::string, int> Inventory; // 아이템 이름 -> 개수

public:
    Character(const std::string& name);

    void ShowStatus() const;
    void AddExp(int amount);
    void AddGold(int amount);
    void SpendGold(int amount);
    void AddItem(const std::string& item, int count = 1);
    void RemoveItem(const std::string& item, int count = 1);
    void ShowInventory() const;

private:
    void LevelUp();
};