#include "HealthPotion.h"
#include "Character.h"
#include <iostream>

HealthPotion::HealthPotion() : Item("체력 회복 포션", 5), HealthRestore(50) {}

void HealthPotion::Use(Character* character)
{
	character->SetHp(character->GetHp() + HealthRestore);
	std::cout << character->GetName() << "의 체력이 " << HealthRestore << " 회복 됐습니다." << std::endl;
}