#include "Character.h"

Character::Character(const std::string& name)
    : Name(name), Level(1), Exp(0), Hp(200), Mp(100),
    Attack(30), Defense(20), Gold(500) { // �⺻ ���� ����
}

Character::~Character() {
    for (auto& pair : Inventory) {
        delete pair.second.first;
    }
    Inventory.clear();
}

void Character::ShowStatus() const {
    std::cout << "===== ĳ���� ���� =====\n";
    std::cout << "�̸�: " << Name << "\n";
    std::cout << "����: " << Level << "\n";
    std::cout << "����ġ: " << Exp << "\n";
    std::cout << "ü��: " << Hp << "\n";
    std::cout << "����: " << Mp << "\n";
    std::cout << "���ݷ�: " << Attack << "\n";
    std::cout << "����: " << Defense << "\n";
    std::cout << "���: " << Gold << "\n";
    std::cout << "======================\n";
}

void Character::AddGold(int amount) {
    Gold += amount;
    std::cout << amount << " ��带 ������ϴ�! (���� ���: " << Gold << ")\n";
}

bool Character::SpendGold(int amount) {
    if (Gold >= amount) {
        Gold -= amount;
        return true;
    }
    std::cout << "��尡 �����մϴ�!\n";
    return false;
}

void Character::AddItem(Item* item, int count) {
    if (!item) return;
    std::string itemName = item->GetName();

    auto it = Inventory.find(itemName);
    if (it == Inventory.end()) {
        Inventory[itemName] = { item, count };
    }
    else {
        if (it->second.second + count > 99) {
            it->second.second = 99;
            std::cout << itemName << " ��(��) �� �̻� ���� �� �����ϴ� (�ִ� 99��).\n";
        }
        else {
            it->second.second += count;
        }
        delete item;
    }

    std::cout << itemName << " x" << count << " �κ��丮�� �߰��Ǿ����ϴ�!\n";
}

bool Character::RemoveItem(const std::string& itemName, int count) {
    auto it = Inventory.find(itemName);
    if (it != Inventory.end()) {
        if (it->second.second >= count) {
            it->second.second -= count;
            if (it->second.second == 0) {
                delete it->second.first;
                Inventory.erase(it);
            }
            std::cout << itemName << " x" << count << " �����߽��ϴ�.\n";
            return true;
        }
    }
    std::cout << itemName << " �������� �����մϴ�.\n";
    return false;
}

void Character::ShowInventory() const {
    std::cout << "===== �κ��丮 =====\n";
    if (Inventory.empty()) {
        std::cout << "�κ��丮�� ����ֽ��ϴ�.\n";
    }
    else {
        for (const auto& pair : Inventory) {
            std::cout << "- " << pair.first << " x" << pair.second.second << "\n";
        }
    }
    std::cout << "====================\n";
}

bool Character::UseItem(const std::string& itemName) {
    auto it = Inventory.find(itemName);
    if (it != Inventory.end() && it->second.second > 0) {
        it->second.first->Use(this);
        RemoveItem(itemName, 1);
        return true;
    }
    std::cout << itemName << " �������� �����ϴ�.\n";
    return false;
}

bool Character::SellItem(const std::string& itemName, int count, float ratio) {
    auto it = Inventory.find(itemName);
    if (it != Inventory.end() && it->second.second >= count) {
        int price = it->second.first->GetPrice();

        // ratio ���� -1.0f �� �⺻ SellRatio ���
        float appliedRatio = (ratio > 0.0f ? ratio : SellRatio);

        int goldEarned = static_cast<int>(price * appliedRatio * count);

        if (RemoveItem(itemName, count)) {
            AddGold(goldEarned);
            std::cout << itemName << " x" << count
                << " �Ǹ� �Ϸ�! +" << goldEarned << " ��� ȹ��\n";
            return true;
        }
    }
    std::cout << itemName << " ��(��) �Ǹ��� �� �����ϴ�.\n";
    return false;
}

void Character::Heal(int amount) {
    Hp += amount;
    std::cout << "ü���� " << amount << " ȸ���Ǿ����ϴ�. (���� ü��: " << Hp << ")\n";
}

void Character::RestoreMp(int amount) {
    Mp += amount;
    std::cout << "������ " << amount << " ȸ���Ǿ����ϴ�. (���� ����: " << Mp << ")\n";
}

void Character::IncreaseAttack(int amount) {
    Attack += amount;
    std::cout << "���ݷ��� " << amount << " �����߽��ϴ�. (���� ���ݷ�: " << Attack << ")\n";
}

void Character::IncreaseDefense(int amount) {
    Defense += amount;
    std::cout << "������ " << amount << " �����߽��ϴ�. (���� ����: " << Defense << ")\n";
}
