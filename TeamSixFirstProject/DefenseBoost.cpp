#include "DefenseBoost.h"

DefenseBoost::DefenseBoost() : Name("방어력 증가 포션"), DefenseIncrease(10),Price(15) {}

std::string DefenseBoost::GetName()
{
    return Name;
}

void DefenseBoost::Use(Character* character)
{
}

int DefenseBoost::GetPrice() const
{
    return Price;
}
