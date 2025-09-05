#include "AttackBoost.h"
#include "Character.h"
#include <iostream>

AttackBoost::AttackBoost() : Item("���ݷ� ���� ����", 10, 10) {}

void AttackBoost::Use(Character* character)
{
	character->SetAttack(character->GetAttack() + Value);
	std::cout << character->GetName() << "�� ���ݷ��� " << Value << " ���� �߽��ϴ�." << std::endl;
}

void AttackBoost::ItemInfo()
{
	std::cout << "���ݷ��� " << Value << " �����մϴ�." << std::endl;
}