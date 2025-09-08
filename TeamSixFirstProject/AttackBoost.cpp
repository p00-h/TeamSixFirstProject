#include "AttackBoost.h"
#include "Character.h"
#include <iostream>

AttackBoost::AttackBoost() : Item("���ݷ� ���� ����", 10, 10, 3) {}

void AttackBoost::Use(Character* character)
{
	Turn = 3;
	character->SetAttack(character->GetAttack() + Value);
	std::cout << character->GetName() << "�� ���ݷ��� " << Turn <<"�� ���� " <<Value << " �����մϴ�.." << std::endl;
}

std::string AttackBoost::ItemInfo()
{
	return "���ݷ��� " + std::to_string(Value) + " �����մϴ�.";
}

Item* AttackBoost::Clone() const
{
	return new AttackBoost(*this);
}

void AttackBoost::ExpireEffect(Character* character)
{
	if (Turn <= 0)
	{
		character->SetAttack(character->GetAttack() - Value);
		std::cout << Name << "�� ȿ���� �������ϴ�." << std::endl;
	}
}