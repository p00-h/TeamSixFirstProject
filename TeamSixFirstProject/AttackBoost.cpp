#include "AttackBoost.h"

AttackBoost::AttackBoost() : Name("공격력 증가 포션"), AttackIncrease(10),Price(10) {}

std::string AttackBoost::GetName()
{
    return Name;
}

void AttackBoost::Use(Character* character)
{
}
