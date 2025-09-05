#include "ManaPotion.h"
#include "Character.h"
#include <iostream>

ManaPotion::ManaPotion() : Item("마나 회복 포션",5), ManaRestore(10) {}

void ManaPotion::Use(Character* character)
{
	character->SetMp(character->GetMp() + ManaRestore);
	std::cout << character->GetName() << "의 마나가 " << ManaRestore << " 회복 됐습니다." << std::endl;
}
