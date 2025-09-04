#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Item.h"

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

    std::map<std::string, Item*> Inventory;

public:
    Character(const std::string& name);
    ~Character();

    void ShowStatus() const;
    void AddExp(int amount);
    void AddGold(int amount);
    bool SpendGold(int amount);
    void AddItem(Item* item);
    void RemoveItem(const std::string& itemName);
    void ShowInventory() const;
    void UseItem(const std::string& itemName);

    // Ω∫≈» ¡∂¿€øÎ
    void Heal(int amount);
    void RestoreMp(int amount);
    void IncreaseAttack(int amount);

private:
    void LevelUp();
};
