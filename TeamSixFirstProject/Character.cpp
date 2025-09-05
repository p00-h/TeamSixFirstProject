#include "Character.h"

Character::Character(const std::string& name) /// �⺻ ���� ����
    : Name(name), Level(1), Hp(200), Mp(100), Attack(30), Defense(20), Exp(0), Gold(500) {
}

Character::~Character() {
    for (auto& pair : Inventory) {
        delete pair.second;
    }
    Inventory.clear();
}

void Character::ShowStatus() const {
    std::cout << "===== ĳ���� ���� =====\n";
    std::cout << "�̸�: " << Name << "\n";
    std::cout << "����: " << Level << "\n";
    std::cout << "ü��(HP): " << Hp << "\n";
    std::cout << "����(MP): " << Mp << "\n";
    std::cout << "���ݷ�: " << Attack << "\n";
    std::cout << "����: " << Defense << "\n";
    std::cout << "����ġ: " << Exp << " / " << ExpToLevelUp << "\n";
    std::cout << "���: " << Gold << "\n";
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
    std::cout << "��� +" << amount << " (���� ���: " << Gold << ")\n";
}

bool Character::SpendGold(int amount) {
    if (Gold >= amount) {
        Gold -= amount;
        std::cout << "��� -" << amount << " (���� ���: " << Gold << ")\n";
        return true;
    }
    else {
        std::cout << "��尡 �����մϴ�! ���� ���: " << Gold << "\n";
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
        std::cout << itemName << "�� �̹� �κ��丮�� �ֽ��ϴ�.\n";
        delete item;
    }
    std::cout << itemName << " �������� �κ��丮�� �߰��Ǿ����ϴ�!\n";
}

void Character::RemoveItem(const std::string& itemName) {
    auto it = Inventory.find(itemName);
    if (it != Inventory.end()) {
        delete it->second;
        Inventory.erase(it);
        std::cout << itemName << " �������� �����߽��ϴ�.\n";
    }
    else {
        std::cout << itemName << " �������� �����ϴ�.\n";
    }
}

void Character::ShowInventory() const {
    std::cout << "===== �κ��丮 =====\n";
    if (Inventory.empty()) {
        std::cout << "�κ��丮�� ����ֽ��ϴ�.\n";
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
        RemoveItem(itemName); /// ������ �� �� ���� ����
    }
    else {
        std::cout << itemName << " �������� �����ϴ�.\n";
    }
}

void Character::Heal(int amount) {
    Hp += amount;
    std::cout << "HP�� " << amount << " ȸ���Ǿ����ϴ�! ���� HP: " << Hp << "\n";
}

void Character::RestoreMp(int amount) {
    Mp += amount;
    std::cout << "MP�� " << amount << " ȸ���Ǿ����ϴ�! ���� MP: " << Mp << "\n";
}

void Character::IncreaseAttack(int amount) {
    Attack += amount;
    std::cout << "���ݷ��� " << amount << " �����߽��ϴ�! ���� ���ݷ�: " << Attack << "\n";
}

void Character::LevelUp() { /// ������ �� ���� ����
    Exp -= ExpToLevelUp;
    Level++;
    Hp += 50;
    Mp += 20;
    Attack += 10;
    Defense += 5;
    std::cout << "������! ���� ����: " << Level << "\n";
}
