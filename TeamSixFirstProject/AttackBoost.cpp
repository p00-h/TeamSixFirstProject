#include "AttackBoost.h"
#include "Character.h"
#include <iostream>

AttackBoost::AttackBoost() : Item("공격력 증가 포션", 10), AttackIncrease(10) {}

void AttackBoost::Use(Character* character)
{
	character->SetAttack(character->GetAttack() + AttackIncrease);
	std::cout << character->GetName() << "의 방어력이 " << AttackIncrease << " 증가 했습니다." << std::endl;
}
