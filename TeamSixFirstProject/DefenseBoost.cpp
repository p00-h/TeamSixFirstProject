#include "DefenseBoost.h"
#include "Character.h"
#include <iostream>

DefenseBoost::DefenseBoost() : Item("���� ���� ����", 15, 10, 3) {}

void DefenseBoost::Use(Character* character)
{
	character->SetDefense(character->GetDefense() + Value);
	std::cout << character->GetName() << "�� ������ " << Value << " ���� �߽��ϴ�." << std::endl;
}

std::string DefenseBoost::ItemInfo()
{
	return "������ " + std::to_string(Value) + " �����մϴ�.";
}

Item* DefenseBoost::Clone() const
{
	return new DefenseBoost(*this);
}

void DefenseBoost::ExpireEffect(Character* character)
{
	if (Turn <= 0)
	{
		character->SetDefense(character->GetDefense() - Value);
		std::cout << Name << "�� ȿ���� �������ϴ�." << std::endl;
	}
}