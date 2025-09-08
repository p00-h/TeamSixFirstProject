#include "AttackBoost.h"
#include "Character.h"
#include <iostream>

AttackBoost::AttackBoost() : Item("공격력 증가 포션", 10, 10, 3) {}

void AttackBoost::Use(Character* character)
{
	Turn = 3;
	character->SetAttack(character->GetAttack() + Value);
	std::cout << character->GetName() << "의 공격력이 " << Turn <<"턴 동안 " <<Value << " 증가합니다.." << std::endl;
}

std::string AttackBoost::ItemInfo()
{
	return "공격력이 " + std::to_string(Value) + " 증가합니다.";
}

Item* AttackBoost::Clone() const
{
	return new AttackBoost(*this);
}

void AttackBoost::ExpireEffect(Character* character)
{
	if (Turn <= 0)
	{
		character->SetAttack(character->GetAttack() - Value);
		std::cout << Name << "의 효과가 끝났습니다." << std::endl;
	}
}