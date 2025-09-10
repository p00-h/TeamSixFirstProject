#include "DefenseBoost.h"

<<<<<<< HEAD
DefenseBoost::DefenseBoost() : Name("���� ���� ����"), DefenseIncrease(10),Price(15) {}

std::string DefenseBoost::GetName()
{
    return Name;
}

void DefenseBoost::Use(Character* character)
{
}
=======
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

void DefenseBoost::EffectIsOver(Character* character)
{
	IsActive = false;
	cout << Name << "�� ȿ���� �������ϴ�." << endl;
	character->SetDefense(character->GetDefense() - Value);
}
>>>>>>> parent of 5e63b35 (Merge branch 'main' into dev)
