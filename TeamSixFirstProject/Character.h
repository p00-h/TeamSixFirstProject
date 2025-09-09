#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Item.h"

class Character {
private:
    std::string Name;
    int Level;
    int Exp;
    int Hp, MaxHp;   // ���� HP, �ִ� HP
    int Mp, MaxMp;   // ���� MP, �ִ� MP
    int Attack;
    int Defense;
    int Gold;

    float SellRatio = 0.5f; // ������ �Ǹ� �� ��� ��� ���� (0.5=50%)

    std::map<std::string, std::pair<Item*, int>> Inventory;

public:
    Character(const std::string& name);
    ~Character();

    // �⺻ ���
    void ShowStatus() const;
    void AddGold(int amount);
    bool SpendGold(int amount);
    void AddItem(Item* item, int count = 1);
    bool RemoveItem(const std::string& itemName, int count = 1);
    void ShowInventory() const;
    bool UseItem(const std::string& itemName);
    bool SellItem(const std::string& itemName, int count, float ratio = -1.0f);
    void ApplyLevelUp();

	// �κ��丮 ���
    const std::map<std::string, std::pair<Item*, int>>& GetInventory() const {
        return Inventory;
    }

    std::map<std::string, std::pair<Item*, int>>& GetInventory() {
        return Inventory;
    }

    // ���� ����
    void Heal(int amount);
    void RestoreMp(int amount);
    void IncreaseAttack(int amount);
    void IncreaseDefense(int amount);

    // Getter , Setter 
    const std::string& GetName() const { return Name; }
    void SetName(const std::string& name) { Name = name; }

    int GetLevel() const { return Level; }
    void SetLevel(int level) { Level = level; }

    int GetExp() const { return Exp; }
    void SetExp(int exp) { Exp = exp; }

    int GetHp() const { return Hp; }
    int GetMaxHp() const { return MaxHp; }
    void SetHp(int value);   // �ִ�ġ ���� �ʵ��� ����
    void SetMaxHp(int value) { MaxHp = value; if (Hp > MaxHp) Hp = MaxHp; }

    int GetMp() const { return Mp; }
    int GetMaxMp() const { return MaxMp; }
    void SetMp(int value);   // �ִ�ġ ���� �ʵ��� ����
    void SetMaxMp(int value) { MaxMp = value; if (Mp > MaxMp) Mp = MaxMp; }

    int GetAttack() const { return Attack; }
    void SetAttack(int attack) { Attack = attack; }

    int GetDefense() const { return Defense; }
    void SetDefense(int defense) { Defense = defense; }

    int GetGold() const { return Gold; }
    void SetGold(int gold) { Gold = gold; }

    float GetSellRatio() const { return SellRatio; }
    void SetSellRatio(float ratio) { SellRatio = ratio; }
};