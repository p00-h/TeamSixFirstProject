#include "HealthPotion.h"
#include "Character.h"
<<<<<<< HEAD

HealthPotion::HealthPotion() : Name("체력 회복 포션"), HealthRestore(50),Price(5) {}

std::string HealthPotion::GetName()
=======
#include <iostream>

HealthPotion::HealthPotion() : Item("체력 회복 포션", 5, 50) {}

bool HealthPotion::Use(Character* character) // 아이템 사용
>>>>>>> parent of 5e63b35 (Merge branch 'main' into dev)
{
	return Name;
}

void HealthPotion::Use(Character* character)
{

}
