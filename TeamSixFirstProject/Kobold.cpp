#include "Kobold.h"
#include <iostream>
using namespace std;

Kobold::Kobold(int level)
	:Monster("�ں�Ʈ", level)
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

void Kobold::PickaxeAttack(Character* target)
{
	int PickaxeAttackDamage = GetAttack() * 1.2;										//���� ���ʽ� ����� ��� ���� ��
//	int KoboldDamage = GetAttack() + AttackBouns;				//���� ���ʽ� ����� ��� �� Kobodl.h �� 14 ����
	cout << GetName() << "�� �Ϲ� ����, ����� : " << PickaxeAttackDamage << endl;
	if (target) target->SetHp(target->GetHp() - PickaxeAttackDamage);
}

void Kobold::OreThrow(Character* target)
{
	int OreThrowDamage = GetAttack() * 1.4;
	cout << GetName() << "�� ���� ������, ����� : " << OreThrowDamage << endl;
	if (target) target->SetHp(target->GetHp() - OreThrowDamage);
}

void Kobold::TramCarRush(Character* target)
{
	int TramCarRushDamage = GetAttack() * 1.8;
	cout << GetName() << "�� ���� ����! ����� : " << TramCarRushDamage << endl;
	if (target) target->SetHp(target->GetHp() - TramCarRushDamage);
}

void Kobold::NormalAttack(Character* target)
{
	int Dmg = GetAttack();
	cout << GetName() << "�� �Ϲ� ����! ����� : " << Dmg << endl;
	//SetMP(GetMP() + 1);	//�Ϲ� ������ �� ����+1
}

void Kobold::UseSkill(Character* target)
{
	int Choice = rand() % 3;	//0~2 �� �ϳ�
	if (Choice == 0) PickaxeAttack(target);
	else if (Choice == 1)OreThrow(target);
	else TramCarRush(target);

	//SetMP(0);	//��ų ��� �� ���� �ʱ�ȭ
}
