#include "DefenseBoost.h"
#include "Character.h"
#include <iostream>

using namespace std;

DefenseBoost::DefenseBoost() : Item("���� ���� ����", 15, 10) {}

bool DefenseBoost::Use(Character* character) // ������ ���
{
	if (IsActive)
	{
		cout << "�̹� " << Name << "�� ȿ���� �������Դϴ�." << endl;
		return false;
	}
	else
	{
		IsActive = true;
		ItemSound();
		character->SetDefense(character->GetDefense() + Value);
		cout << character->GetName() << "�� ������ " << Value << " �����մϴ�." << endl;
		return true;
	}
}

string DefenseBoost::ItemInfo() const // ������ ����
{
	return "������ " + to_string(Value) + " �����մϴ�.";
}

Item* DefenseBoost::Clone() const // ������ ����
{
	return new DefenseBoost(*this);
}

bool DefenseBoost::IsDurationBased() const // ����������
{
	return true;
}
