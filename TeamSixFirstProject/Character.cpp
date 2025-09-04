#include "Character.h"

Character::Character(const std::string& name) /// 초기 스탯 설정
    : Name(name), Level(1), Hp(200), Mp(100), Attack(30), Defense(20), Exp(0), Gold(500) {
}

void Character::ShowStatus() const {
    std::cout << "======= 상태창 =======\n";
    std::cout << "이름: " << Name << "\n";
    std::cout << "레벨: " << Level << "\n";
    std::cout << "체력(HP): " << Hp << "\n";
    std::cout << "마나(MP): " << Mp << "\n";
    std::cout << "공격력: " << Attack << "\n";
    std::cout << "방어력: " << Defense << "\n";
    std::cout << "경험치: " << Exp << " / " << ExpToLevelUp << "\n";
    std::cout << "골드: " << Gold << "\n";
    std::cout << "=======================\n";
}

void Character::AddExp(int amount) {
    Exp += amount;
    while (Exp >= ExpToLevelUp) {
        LevelUp();
    }
}

void Character::AddGold(int amount) {
    Gold += amount;
    std::cout << "골드 +" << amount << " (현재 골드: " << Gold << ")\n";
}

void Character::SpendGold(int amount) {
    if (Gold >= amount) {
        Gold -= amount;
        std::cout << "골드 -" << amount << " (현재 골드: " << Gold << ")\n";
    }
    else {
        std::cout << "골드가 부족합니다! 현재 골드: " << Gold << "\n";
    }
}

void Character::AddItem(const std::string& item, int count) {
    Inventory[item] += count;
    std::cout << item << " x" << count << " 을(를) 획득했습니다! (총 개수: " << Inventory[item] << ")\n";
}

void Character::RemoveItem(const std::string& item, int count) {
    auto it = Inventory.find(item);
    if (it != Inventory.end()) {
        if (it->second > count) {
            it->second -= count;
            std::cout << item << " x" << count << " 을(를) 잃었습니다! (남은 개수: " << it->second << ")\n";
        }
        else {
            std::cout << item << " 을(를) 전부 잃었습니다!\n";
            Inventory.erase(it);
        }
    }
    else {
        std::cout << item << " 아이템이 인벤토리에 없습니다.\n";
    }
}

void Character::ShowInventory() const { 
    std::cout << "===== 인벤토리 =====\n";
    if (Inventory.empty()) {
        std::cout << "인벤토리가 비어있습니다.\n";
    }
    else {
        for (const auto& pair : Inventory) {
            std::cout << "- " << pair.first << " x" << pair.second << "\n";
        }
    }
    std::cout << "====================\n";
}

void Character::LevelUp() { /// 레벨업 시 능력치 증가
    Exp -= ExpToLevelUp;
    Level++;
    Hp += 50;
    Mp += 20;
    Attack += 10;
    Defense += 5;
    std::cout << "레벨업! 현재 레벨: " << Level << "\n";
}
