#include "Character.h"

Character::Character(const std::string& name) // �ʱ� ���� ����
    : Name(name), Level(1), Exp(0),
    MaxHp(100), Hp(100),
    MaxMp(50), Mp(50),
    Attack(10), Defense(5), Gold(100)
{
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
    std::cout << "ü��: " << Hp << " / " << MaxHp << "\n";
    std::cout << "����: " << Mp << " / " << MaxMp << "\n";
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

bool Character::AddItem(Item* item, int count) {
    if (!item) return false;

    std::string itemName = item->GetName();
    auto it = Inventory.find(itemName);

    if (it == Inventory.end()) {
        Inventory[itemName] = { item->Clone(), count };
        std::cout << itemName << " x" << count << " �κ��丮�� �߰��Ǿ����ϴ�!\n";
        return true;
    }
    else {
        if (it->second.second + count > 99) {
            it->second.second = 99;
            std::cout << itemName << " ��(��) �� �̻� ���� �� �����ϴ� (�ִ� 99��).\n";
            return false;
        }
        else {
            it->second.second += count;
            return true;
        }
        delete item;
    }
    
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
    if (it == Inventory.end()) return false;

    Item* item = it->second.first;
    if (!item) return false;

    if (item->Use(this)) {
        if (--it->second.second <= 0) {
            delete it->second.first;
            Inventory.erase(it);
        }
        return true;
    }
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

void Character::SetHp(int value)
{
    Hp = std::min(value, MaxHp); 
}

void Character::SetMp(int value)
{
    Mp = std::min(value, MaxMp);
}

void Character::ApplyLevelUp() {
    Level += 1;
    // �������� �Ѱ��� ����
    int HpUp = Level * 20;
    int MpUp = 10;
    int AtkUp = Level * 5;
    int DefUp = 3;

    SetMaxHp(MaxHp + HpUp);
    SetMaxMp(MaxMp + MpUp);
    SetAttack(Attack + AtkUp);
    SetDefense(Defense + DefUp);

    SetHp(MaxHp);
    SetMp(MaxMp);

    std::cout << "[������!] +HP " << HpUp
        << ", +MP " << MpUp
        << ", +ATK " << AtkUp
        << ", +DEF " << DefUp << "\n";
}