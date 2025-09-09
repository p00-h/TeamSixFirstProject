#include "DefenseBoost.h"
#include "Character.h"
#include <iostream>

using namespace std;

DefenseBoost::DefenseBoost() : Item("���� ���� ����", 15, 10, -1) {}

void DefenseBoost::Use(Character* character) // ������ ���
{
	if (Turn <= 0) // ������ ȿ�� ��ø ����
	{
		ItemSound();
		Turn = 3;
		character->SetDefense(character->GetDefense() + Value);
		cout << character->GetName() << "�� ������ " << Turn << "�� ���� " << Value << " �����մϴ�." << endl;
	}
	else
	{
		cout << "�̹� " << Name << "�� ȿ���� �������Դϴ�." << endl;
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

void DefenseBoost::TurnDecrease(Character* character) // �� ���� �� ������ ȿ�� �����
{
	if (Turn < 0)
	{
		return;
	}

	if (Turn == 0)
	{
		character->SetDefense(character->GetDefense() - Value);
		cout << Name << "�� ȿ���� �������ϴ�." << endl;
		Turn = -1;

	}
	else
	{
		cout << Name << "�� ȿ���� " << Turn << "�� ���ҽ��ϴ�." << endl;
	}
}