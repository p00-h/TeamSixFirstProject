#include "HealthPotion.h"
#include "Character.h"
#include <iostream>

HealthPotion::HealthPotion() : Item("체력 회복 포션", 5, 50) {}

void HealthPotion::Use(Character* character)
{
	character->SetHp(character->GetHp() + Value);
	std::cout << character->GetName() << "의 체력이 " << Value << " 회복 됐습니다." << std::endl;
}

std::string HealthPotion::ItemInfo()
{
	return "체력을 " + std::to_string(Value) + " 회복합니다.";
}
