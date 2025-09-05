#include "AttackBoost.h"
#include "Character.h"
#include <iostream>

AttackBoost::AttackBoost() : Item("���ݷ� ���� ����", 10), AttackIncrease(10) {}

void AttackBoost::Use(Character* character)
{
	character->SetAttack(character->GetAttack() + AttackIncrease);
	std::cout << character->GetName() << "�� ������ " << AttackIncrease << " ���� �߽��ϴ�." << std::endl;
}
