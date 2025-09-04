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

    //배틀에서 사용하지 않을 예정입니다 필요없다면 배틀 이외에 사용처가 없다면 제거 요망합니다
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
    //기준점
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
    //기준점 부터 여기까지 (박찬영) 제가 임의로 만든 멤버 함수입니다 
private:
    void LevelUp();
};