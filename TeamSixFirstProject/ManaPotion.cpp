#include "ManaPotion.h"

ManaPotion::ManaPotion() : Name("���� ȸ�� ����"), ManaRestore(10), Price(5) {}

std::string ManaPotion::GetName()
{
    return Name;
}

void ManaPotion::Use(Character* character)
{
}
