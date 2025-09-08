#include "Dragon.h"
#include <iostream>
using namespace std;

Dragon::Dragon(int level)
	:Monster("Dragon", level)
{
	SetHP(GetHP() + 100);
	SetAttack(GetAttack() + 40);
	SetMP(0);
}

void Dragon::FireBrass()
{
	int FireBrassDamage = GetAttack() * 1.5;
	cout << " ����� ���Ⱑ �߰ſ����� �����ߴ�.\n"
		<< GetName() << "�� ���̾�귡��! ����� : " << FireBrassDamage << endl;
}

void Dragon::TailSwing()
{
	int TailSwingDamage = GetAttack() * 1.2;
	cout << GetName() << "�� �������� ���� ����! ����� : " << TailSwingDamage << endl;
}

void Dragon::DeadlyCharge()
{
	int DeadlyCharg = GetAttack() * 1.4;
	cout << GetName() << "�� ���� �����̴�! ����� : " << DeadlyCharg << endl;
}

void Dragon::NormalAttack()
{
	int Dmg = GetAttack();
	cout << GetName() << "�� �Ϲ� ����! ����� : " << Dmg << endl;
	//SetMP(GetMP() + 1);	//�Ϲ� ������ �� ����+1
}

void Dragon::UseSkill()
{
	int Choice = rand() % 3;	//���� ��ų 0~2�� �ϳ�
	if (Choice == 0) FireBrass();
	else if (Choice == 1) TailSwing();
	else DeadlyCharge();
	//SetMP(0); //��ų ��� �� ���� �ʱ�ȭ.
}