#include "AttackBoost.h"

AttackBoost::AttackBoost() : Name("���ݷ� ���� ����"), AttackIncrease(10),Price(10) {}

std::string AttackBoost::GetName()
{
    return Name;
}

void AttackBoost::Use(Character* character)
{
}
