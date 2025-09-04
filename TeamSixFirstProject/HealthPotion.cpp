#include "HealthPotion.h"
//#include "Character.h"

HealthPotion::HealthPotion() : Name("체력 회복 포션"), HealthRestore(50) {}

std::string HealthPotion::GetName()
{
	return Name;
}

void HealthPotion::Use(Character* character)
{

}
