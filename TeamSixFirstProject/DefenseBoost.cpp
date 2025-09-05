#include "DefenseBoost.h"
#include "Character.h"
#include <iostream>

DefenseBoost::DefenseBoost() : Item("���� ���� ����", 15, 10) {}

void DefenseBoost::Use(Character* character)
{
	character->SetDefense(character->GetDefense() + Value);
	std::cout << character->GetName() << "�� ������ " << Value << " ���� �߽��ϴ�." << std::endl;
}

void DefenseBoost::ItemInfo()
{
	std::cout << "������ " << Value << " �����մϴ�." << std::endl;
}