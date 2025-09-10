#include "Character.h"

Character::Character(const std::string& name) // 초기 스탯 설정
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
    std::cout << "===== 캐릭터 상태 =====\n";
    std::cout << "이름: " << Name << "\n";
    std::cout << "레벨: " << Level << "\n";
    std::cout << "경험치: " << Exp << "\n";
    std::cout << "체력: " << Hp << " / " << MaxHp << "\n";
    std::cout << "마나: " << Mp << " / " << MaxMp << "\n";
    std::cout << "공격력: " << Attack << "\n";
    std::cout << "방어력: " << Defense << "\n";
    std::cout << "골드: " << Gold << "\n";
    std::cout << "======================\n";
}

void Character::AddGold(int amount) {
    Gold += amount;
    std::cout << amount << " 골드를 얻었습니다! (현재 골드: " << Gold << ")\n";
}

bool Character::SpendGold(int amount) {
    if (Gold >= amount) {
        Gold -= amount;
        return true;
    }
    std::cout << "골드가 부족합니다!\n";
    return false;
}

bool Character::AddItem(Item* item, int count) {
    if (!item) return false;

    std::string itemName = item->GetName();
    auto it = Inventory.find(itemName);

    if (it == Inventory.end()) {
        Inventory[itemName] = { item->Clone(), count };
        std::cout << itemName << " x" << count << " 인벤토리에 추가되었습니다!\n";
        return true;
    }
    else {
        if (it->second.second + count > 99) {
            it->second.second = 99;
            std::cout << itemName << " 은(는) 더 이상 가질 수 없습니다 (최대 99개).\n";
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
    std::cout << itemName << " 아이템이 부족합니다.\n";
    return false;
}

void Character::ShowInventory() const {
    std::cout << "===== 인벤토리 =====\n";
    if (Inventory.empty()) {
        std::cout << "인벤토리가 비어있습니다.\n";
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

        // ratio 값이 -1.0f 면 기본 SellRatio 사용
        float appliedRatio = (ratio > 0.0f ? ratio : SellRatio);

        int goldEarned = static_cast<int>(price * appliedRatio * count);

        if (RemoveItem(itemName, count)) {
            AddGold(goldEarned);
            std::cout << itemName << " x" << count
                << " 판매 완료! +" << goldEarned << " 골드 획득\n";
            return true;
        }
    }
    std::cout << itemName << " 을(를) 판매할 수 없습니다.\n";
    return false;
}

void Character::Heal(int amount) {
    Hp += amount;
    std::cout << "체력이 " << amount << " 회복되었습니다. (현재 체력: " << Hp << ")\n";
}

void Character::RestoreMp(int amount) {
    Mp += amount;
    std::cout << "마나가 " << amount << " 회복되었습니다. (현재 마나: " << Mp << ")\n";
}

void Character::IncreaseAttack(int amount) {
    Attack += amount;
    std::cout << "공격력이 " << amount << " 증가했습니다. (현재 공격력: " << Attack << ")\n";
}

void Character::IncreaseDefense(int amount) {
    Defense += amount;
    std::cout << "방어력이 " << amount << " 증가했습니다. (현재 방어력: " << Defense << ")\n";
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
    // 증가량은 한곳에 고정
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

    std::cout << "[레벨업!] +HP " << HpUp
        << ", +MP " << MpUp
        << ", +ATK " << AtkUp
        << ", +DEF " << DefUp << "\n";
}