#include "Character.h"

Character::Character(const std::string& name) /// �ʱ� ���� ����
    : Name(name), Level(1), Hp(200), Mp(100), Attack(30), Defense(20), Exp(0), Gold(500) {
}

void Character::ShowStatus() const {
    std::cout << "======= ����â =======\n";
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

void Character::SpendGold(int amount) {
    if (Gold >= amount) {
        Gold -= amount;
        std::cout << "��� -" << amount << " (���� ���: " << Gold << ")\n";
    }
    else {
        std::cout << "��尡 �����մϴ�! ���� ���: " << Gold << "\n";
    }
}

void Character::AddItem(const std::string& item, int count) {
    Inventory[item] += count;
    std::cout << item << " x" << count << " ��(��) ȹ���߽��ϴ�! (�� ����: " << Inventory[item] << ")\n";
}

void Character::RemoveItem(const std::string& item, int count) {
    auto it = Inventory.find(item);
    if (it != Inventory.end()) {
        if (it->second > count) {
            it->second -= count;
            std::cout << item << " x" << count << " ��(��) �Ҿ����ϴ�! (���� ����: " << it->second << ")\n";
        }
        else {
            std::cout << item << " ��(��) ���� �Ҿ����ϴ�!\n";
            Inventory.erase(it);
        }
    }
    else {
        std::cout << item << " �������� �κ��丮�� �����ϴ�.\n";
    }
}

void Character::ShowInventory() const { 
    std::cout << "===== �κ��丮 =====\n";
    if (Inventory.empty()) {
        std::cout << "�κ��丮�� ����ֽ��ϴ�.\n";
    }
    else {
        for (const auto& pair : Inventory) {
            std::cout << "- " << pair.first << " x" << pair.second << "\n";
        }
    }
    std::cout << "====================\n";
}

void Character::LevelUp() { /// ������ �� �ɷ�ġ ����
    Exp -= ExpToLevelUp;
    Level++;
    Hp += 50;
    Mp += 20;
    Attack += 10;
    Defense += 5;
    std::cout << "������! ���� ����: " << Level << "\n";
}
