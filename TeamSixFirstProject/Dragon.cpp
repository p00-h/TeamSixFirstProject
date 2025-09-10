#include "Dragon.h"
#include "Character.h"
#include <iostream>
using namespace std;

Dragon::Dragon(int level)
	:Monster("�巡��", level)
{
	SetHP(GetHP() + 100);
	SetAttack(GetAttack() + 40);
	SetMP(0);
}

void Dragon::FireBrass(Character* target)
{
	int FireBrassDamage = GetAttack() * 1.5;
	cout << " ����� ���Ⱑ �߰ſ����� �����ߴ�.\n"
		<< GetName() << "�� ���̾�귡��! ����� : " << FireBrassDamage << endl;
	if (target) target->SetHp(target->GetHp() - FireBrassDamage);
}

void Dragon::TailSwing(Character* target)
{
	int TailSwingDamage = GetAttack() * 1.2;
	cout << GetName() << "�� �������� ���� ����! ����� : " << TailSwingDamage << endl;
	if (target) target->SetHp(target->GetHp() - TailSwingDamage);
}

void Dragon::DeadlyCharge(Character* target)
{
	int DeadlyCharg = GetAttack() * 1.4;
	cout << GetName() << "�� ���� �����̴�! ����� : " << DeadlyCharg << endl;
	if (target) target->SetHp(target->GetHp() - DeadlyCharg);
}

void Dragon::NormalAttack(Character* target)
{
	int Dmg = GetAttack();
	cout << GetName() << "�� �Ϲ� ����! ����� : " << Dmg << endl;
	//SetMP(GetMP() + 1);	//�Ϲ� ������ �� ����+1
}

void Dragon::UseSkill(Character* target)
{
	int Choice = rand() % 3;	//���� ��ų 0~2�� �ϳ�
	if (Choice == 0) FireBrass(target);
	else if (Choice == 1) TailSwing(target);
	else DeadlyCharge(target);
	//SetMP(0); //��ų ��� �� ���� �ʱ�ȭ.
}