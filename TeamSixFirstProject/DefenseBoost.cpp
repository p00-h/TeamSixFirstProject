#include "DefenseBoost.h"

DefenseBoost::DefenseBoost() : Name("���� ���� ����"), DefenseIncrease(10) {}

std::string DefenseBoost::GetName()
{
    return Name;
}

void DefenseBoost::Use(Character* character)
{
}
