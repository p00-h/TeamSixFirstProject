#include "ManaPotion.h"

ManaPotion::ManaPotion() : Name("마나 회복 포션"), ManaRestore(10), Price(5) {}

std::string ManaPotion::GetName()
{
    return Name;
}

void ManaPotion::Use(Character* character)
{
}
