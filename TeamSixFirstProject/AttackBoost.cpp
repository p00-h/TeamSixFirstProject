#include "AttackBoost.h"
#include "Character.h"
#include <iostream>

using namespace std;

AttackBoost::AttackBoost() : Item("���ݷ� ���� ����", 10, 10) {}

bool AttackBoost::Use(Character* character) // ������ ���
{
	if (IsActive) // ������ ȿ�� ��ø ����
	{
		cout << "�̹� " << Name << "�� ȿ���� �������Դϴ�." << endl;
		return false;
	}
	else
	{
		IsActive = true;
		ItemSound();
		character->SetAttack(character->GetAttack() + Value);
		cout << character->GetName() << "�� ���ݷ��� " << Value << " �����մϴ�." << endl;
		return true;
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

bool AttackBoost::IsDurationBased() const // ����������
{
	return true;
}