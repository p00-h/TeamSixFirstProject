#include "DefenseBoost.h"
#include "Character.h"
#include <iostream>

DefenseBoost::DefenseBoost() : Item("방어력 증가 포션", 15, 10, 3) {}

void DefenseBoost::Use(Character* character)
{
	character->SetDefense(character->GetDefense() + Value);
	std::cout << character->GetName() << "의 방어력이 " << Value << " 증가 했습니다." << std::endl;
}

std::string DefenseBoost::ItemInfo()
{
	return "방어력이 " + std::to_string(Value) + " 증가합니다.";
}

Item* DefenseBoost::Clone() const
{
	return new DefenseBoost(*this);
}

void DefenseBoost::ExpireEffect(Character* character)
{
	if (Turn <= 0)
	{
		character->SetDefense(character->GetDefense() - Value);
		std::cout << Name << "의 효과가 끝났습니다." << std::endl;
	}
}