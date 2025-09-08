#include "Kobold.h"
#include <iostream>
using namespace std;

Kobold::Kobold(int level)
	:Monster("Kobold", level)
{														//Monster.h�� HP�� Attack�� private�� �����ϸ鼭 ���� ����
	SetHP(GetHP() + 10);
	SetAttack(GetAttack() + 2);
	SetMP(0);
														//Monster.h��  HP�� Attack�� protected ��� ��
	//HP += 10;
	//Attack += 15;
														//Kobold.h�� ���� ���ʽ� ����� ��� ��, Kobold.h �� 14����
	//AttackBouns = level * 2;
}

void Kobold::PickaxeAttack()
{
	int PickaxeAttackDamage = GetAttack() * 1.2;										//���� ���ʽ� ����� ��� ���� ��
//	int KoboldDamage = GetAttack() + AttackBouns;				//���� ���ʽ� ����� ��� �� Kobodl.h �� 14 ����
	cout << GetName() << "�� �Ϲ� ����, ����� : " << PickaxeAttackDamage << endl;
}

void Kobold::OreThrow()
{
	int OreThrowDamage = GetAttack() * 1.4;
	cout << GetName() << "�� ���� ������, ����� : " << OreThrowDamage << endl;
}

void Kobold::TramCarRush()
{
	int TramCarRushDamage = GetAttack() * 1.8;
	cout << GetName() << "�� ���� ����! ����� : " << TramCarRushDamage << endl;
}

void Kobold::NormalAttack()
{
	int Dmg = GetAttack();
	cout << GetName() << "�� �Ϲ� ����! ����� : " << Dmg << endl;
	//SetMP(GetMP() + 1);	//�Ϲ� ������ �� ����+1
}

void Kobold::UseSkill()
{
	int Choice = rand() % 3;	//0~2 �� �ϳ�
	if (Choice == 0) PickaxeAttack();
	else if (Choice == 1)OreThrow();
	else TramCarRush();

	//SetMP(0);	//��ų ��� �� ���� �ʱ�ȭ
}
