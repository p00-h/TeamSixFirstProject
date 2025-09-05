#include "DefenseBoost.h"
#include "Character.h"
#include <iostream>

DefenseBoost::DefenseBoost() : Item("���� ���� ����", 15), DefenseIncrease(10) {}

void DefenseBoost::Use(Character* character)
{
	character->SetDefense(character->GetDefense() + DefenseIncrease);
	std::cout << character->GetName() << "�� ������ " << DefenseIncrease << " ���� �߽��ϴ�." << std::endl;
}