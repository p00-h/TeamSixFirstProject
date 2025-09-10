#include "Orc.h"
#include <iostream>
using namespace std;

Orc::Orc(int level)
	:Monster("��ũ", level)
{
	SetHP(GetHP() + 20);
	SetAttack(GetAttack() + 10);
	SetMP(0);
										//���� ���ʽ� ����� ��� ��
	//OrcBouns = level * 5;
}

void Orc::BellyFatAttack(Character* target)
{
	int BellyFatAttackDamage = GetAttack() * 1.5;
	cout << GetName() << "�� ��� ����! ����� ���ڴ�.. ����� : " << BellyFatAttackDamage << endl;
	if (target) target->SetHp(target->GetHp() - BellyFatAttackDamage);
}

void Orc::ClubAttack(Character* target)
{
	int ClubAttackDamage = GetAttack() * 1.2;
	cout << GetName() << "�� ������ ����! ����� : " << ClubAttackDamage << endl;
	if (target) target->SetHp(target->GetHp() - ClubAttackDamage);
}

void Orc::GroundShaking(Character* target)
{
	int GroundShakingDamage = GetAttack() * 2;
	cout << GetName() << "�� ���︲!! ����� : " << GroundShakingDamage << endl;
	if (target) target->SetHp(target->GetHp() - GroundShakingDamage);
}

void Orc::NormalAttack(Character* target)
{
	int Dmg = GetAttack();
	cout << GetName() << "�� �Ϲ� ����! ����� : " << Dmg << endl;
	//SetMP(GetMP() + 1);	//���ݽ� ����+1
}

void Orc::UseSkill(Character* target)
{
	int Choice = rand() % 3;
	if (Choice == 0)  BellyFatAttack(target);
	else if (Choice == 1) ClubAttack(target);
	else GroundShaking(target);

	//SetMP(0);	//���� �ʱ�ȭ
}