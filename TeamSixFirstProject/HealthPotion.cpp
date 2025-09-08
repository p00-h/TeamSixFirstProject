#include "HealthPotion.h"
#include "Character.h"
#include <iostream>

HealthPotion::HealthPotion() : Item("체력 회복 포션", 5, 50, 0) {}

void HealthPotion::Use(Character* character) // 아이템 사용
{
	character->SetHp(character->GetHp() + Value);
	std::cout << character->GetName() << "의 체력이 " << Value << " 회복 됐습니다." << std::endl;
}

std::string HealthPotion::ItemInfo() const // 아이템 정보
{
	return "체력을 " + std::to_string(Value) + " 회복합니다.";
}

Item* HealthPotion::Clone() const // 아이템 복제
{
	return new HealthPotion(*this);
}