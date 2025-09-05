#include "ManaPotion.h"
#include "Character.h"
#include <iostream>

ManaPotion::ManaPotion() : Item("마나 회복 포션",5, 10) {}

void ManaPotion::Use(Character* character)
{
	character->SetMp(character->GetMp() + Value);
	std::cout << character->GetName() << "의 마나가 " << Value << " 회복 됐습니다." << std::endl;
}

void ManaPotion::ItemInfo()
{
	std::cout << "마나를 " << Value << " 회복합니다." << std::endl;
}
