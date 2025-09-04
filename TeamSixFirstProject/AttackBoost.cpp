#include "AttackBoost.h"

AttackBoost::AttackBoost() : Name("공격력 상승 포션"), AttackIncrease(10) {}

std::string AttackBoost::GetName()
{
    return Name;
}

void AttackBoost::Use(Character* character)
{
}
