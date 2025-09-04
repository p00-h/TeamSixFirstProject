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

    //��Ʋ���� ������� ���� �����Դϴ� �ʿ���ٸ� ��Ʋ �̿ܿ� ���ó�� ���ٸ� ���� ����մϴ�
    const int ExpToLevelUp = 100;

    std::map<std::string, int> Inventory; // ������ �̸� -> ����

public:
    Character(const std::string& name);

    void ShowStatus() const;
    void AddExp(int amount);
    void AddGold(int amount);
    void SpendGold(int amount);
    void AddItem(const std::string& item, int count = 1);
    void RemoveItem(const std::string& item, int count = 1);
    void ShowInventory() const;
    //������
    int GetHP() const;
    void SetHP(const int& hp);
    int GetAttack() const;
    void SetAttack(const int& attack);
    int GetGold() const;
    void SetGold(const int& gold);
    int GetExp() const;
    void SetExp(const int& exp);
    int GetLevel() const;
    void SetLevel(const int& level);
    //������ ���� ������� (������) ���� ���Ƿ� ���� ��� �Լ��Դϴ� 
private:
    void LevelUp();
};