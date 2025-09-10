#include "AttackBoost.h"
#include "Character.h"
#include <iostream>

using namespace std;

AttackBoost::AttackBoost() : Item("���ݷ� ���� ����", 10, 10, -1) {}

bool AttackBoost::Use(Character* character) // ������ ���
{
	if (Turn <= 0) // ������ ȿ�� ��ø ����
	{
		ItemSound();
		Turn = 3;
		character->SetAttack(character->GetAttack() + Value);
		cout << character->GetName() << "�� ���ݷ��� " << Turn << "�� ���� " << Value << " �����մϴ�." << endl;
		return true;
	}
	else
	{
		cout << "�̹� " << Name << "�� ȿ���� �������Դϴ�." << endl;
		return false;
	}
}

string AttackBoost::ItemInfo() const // ������ ����
{
	return "���ݷ��� " + to_string(Value) + " �����մϴ�.";
}

Item* AttackBoost::Clone() const // ������ ����
{
	return new AttackBoost(*this);
}

void AttackBoost::TurnDecrease(Character* character) // �� ���� �� ������ ȿ�� �����
{
	if(Turn < 0)
	{
		return;
	}

	if (Turn == 0)
	{
		character->SetAttack(character->GetAttack() - Value);
		cout << Name << "�� ȿ���� �������ϴ�." << endl;

	}
	else
	{
		cout << Name << "�� ȿ���� " << Turn << "�� ���ҽ��ϴ�." << endl;
	}
}