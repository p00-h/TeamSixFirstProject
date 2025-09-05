#include "DefenseBoost.h"
#include "Character.h"
#include <iostream>

DefenseBoost::DefenseBoost() : Item("방어력 증가 포션", 15), DefenseIncrease(10) {}

void DefenseBoost::Use(Character* character)
{
	character->SetDefense(character->GetDefense() + DefenseIncrease);
	std::cout << character->GetName() << "의 방어력이 " << DefenseIncrease << " 증가 했습니다." << std::endl;
}