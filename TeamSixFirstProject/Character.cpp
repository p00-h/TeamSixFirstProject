#include "Character.h"

Character::Character(const std::string& name) /// 기본 스탯 설정
    : Name(name), Level(1), Hp(200), Mp(100), Attack(30), Defense(20), Exp(0), Gold(500) {
}

Character::~Character() {
    for (auto& pair : Inventory) {
        delete pair.second;
    }
    Inventory.clear();
}

void Character::ShowStatus() const {
    std::cout << "===== 캐릭터 상태 =====\n";
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

bool Character::SpendGold(int amount) {
    if (Gold >= amount) {
        Gold -= amount;
        std::cout << "골드 -" << amount << " (현재 골드: " << Gold << ")\n";
        return true;
    }
    else {
        std::cout << "골드가 부족합니다! 현재 골드: " << Gold << "\n";
        return false;
    }
}

void Character::AddItem(Item* item) {
    if (!item) return;
    std::string itemName = item->GetName();
    if (Inventory.find(itemName) == Inventory.end()) {
        Inventory[itemName] = item;
    }
    else {
        std::cout << itemName << "은 이미 인벤토리에 있습니다.\n";
        delete item;
    }
    std::cout << itemName << " 아이템이 인벤토리에 추가되었습니다!\n";
}

void Character::RemoveItem(const std::string& itemName) {
    auto it = Inventory.find(itemName);
    if (it != Inventory.end()) {
        delete it->second;
        Inventory.erase(it);
        std::cout << itemName << " 아이템을 제거했습니다.\n";
    }
    else {
        std::cout << itemName << " 아이템이 없습니다.\n";
    }
}

void Character::ShowInventory() const {
    std::cout << "===== 인벤토리 =====\n";
    if (Inventory.empty()) {
        std::cout << "인벤토리가 비어있습니다.\n";
    }
    else {
        for (const auto& pair : Inventory) {
            std::cout << "- " << pair.first << "\n";
        }
    }
    std::cout << "====================\n";
}

void Character::UseItem(const std::string& itemName) {
    auto it = Inventory.find(itemName);
    if (it != Inventory.end()) {
        it->second->Use(this);
        RemoveItem(itemName); /// 아이템 한 번 쓰면 삭제
    }
    else {
        std::cout << itemName << " 아이템이 없습니다.\n";
    }
}

void Character::Heal(int amount) {
    Hp += amount;
    std::cout << "HP가 " << amount << " 회복되었습니다! 현재 HP: " << Hp << "\n";
}

void Character::RestoreMp(int amount) {
    Mp += amount;
    std::cout << "MP가 " << amount << " 회복되었습니다! 현재 MP: " << Mp << "\n";
}

void Character::IncreaseAttack(int amount) {
    Attack += amount;
    std::cout << "공격력이 " << amount << " 증가했습니다! 현재 공격력: " << Attack << "\n";
}

void Character::LevelUp() { /// 레벨업 시 스탯 증가
    Exp -= ExpToLevelUp;
    Level++;
    Hp += 50;
    Mp += 20;
    Attack += 10;
    Defense += 5;
    std::cout << "레벨업! 현재 레벨: " << Level << "\n";
}
