#include "AttackBoost.h"

<<<<<<< HEAD
AttackBoost::AttackBoost() : Name("���ݷ� ���� ����"), AttackIncrease(10),Price(10) {}

std::string AttackBoost::GetName()
{
    return Name;
}

void AttackBoost::Use(Character* character)
{
}
=======
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

void AttackBoost::EffectIsOver(Character* character)
{
	IsActive = false;
	cout << Name << "�� ȿ���� �������ϴ�." << endl;
	character->SetAttack(character->GetAttack() - Value);
}
>>>>>>> parent of 5e63b35 (Merge branch 'main' into dev)
