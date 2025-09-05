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

    std::map<std::string, Item*> Inventory; // ������ �̸� -> ������ ������

    const std::map<std::string, std::pair<Item*, int>>& GetInventory() const {
        return Inventory;
    }

    std::map<std::string, std::pair<Item*, int>>& GetInventory() {
        return Inventory;
    }

public:
    Character(const std::string& name);
    ~Character();

    // �⺻ ���
    void ShowStatus() const;
    void AddExp(int amount);
    void AddGold(int amount);
    bool SpendGold(int amount);
    void AddItem(Item* item);
    bool RemoveItem(const std::string& itemName);
    void ShowInventory() const;
    bool UseItem(const std::string& itemName);
    bool SellItem(const std::string& itemName, int count, float ratio = -1.0f);

    // ���� ���ۿ�
    void Heal(int amount);
    void RestoreMp(int amount);
    void IncreaseAttack(int amount);
    void IncreaseDefense(int amount);

    /// Getters , Setters �߰� 
    const std::string& GetName() const { return Name; }
    void SetName(const std::string& name) { Name = name; }

    int GetLevel() const { return Level; }
    void SetLevel(int level) { Level = level; }

    int GetHp() const { return Hp; }
    void SetHp(int hp) { Hp = hp; }

    int GetMp() const { return Mp; }
    void SetMp(int mp) { Mp = mp; }

    int GetAttack() const { return Attack; }
    void SetAttack(int attack) { Attack = attack; }

    int GetDefense() const { return Defense; }
    void SetDefense(int defense) { Defense = defense; }

    int GetExp() const { return Exp; }
    void SetExp(int exp) { Exp = exp; }

    int GetGold() const { return Gold; }
    void SetGold(int gold) { Gold = gold; }

private:
    void LevelUp();
};
