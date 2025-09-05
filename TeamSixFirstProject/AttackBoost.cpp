#include "AttackBoost.h"
#include "Character.h"
#include <iostream>

AttackBoost::AttackBoost() : Item("공격력 증가 포션", 10, 10) {}

void AttackBoost::Use(Character* character)
{
	character->SetAttack(character->GetAttack() + Value);
	std::cout << character->GetName() << "의 공격력이 " << Value << " 증가 했습니다." << std::endl;
}

void AttackBoost::ItemInfo()
{
	std::cout << "공격력이 " << Value << " 증가합니다." << std::endl;
}