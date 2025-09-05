#include "DefenseBoost.h"
#include "Character.h"
#include <iostream>

DefenseBoost::DefenseBoost() : Item("방어력 증가 포션", 15, 10) {}

void DefenseBoost::Use(Character* character)
{
	character->SetDefense(character->GetDefense() + Value);
	std::cout << character->GetName() << "의 방어력이 " << Value << " 증가 했습니다." << std::endl;
}

void DefenseBoost::ItemInfo()
{
	std::cout << "방어력이 " << Value << " 증가합니다." << std::endl;
}