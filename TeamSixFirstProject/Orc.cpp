#include "Orc.h"
#include <iostream>
using namespace std;

Orc::Orc(int level)
	:Monster("Orc", level)
{
	SetHP(GetHP() + 20);
	SetAttack(GetAttack() + 10);
	SetMP(0);
										//���� ���ʽ� ����� ��� ��
	//OrcBouns = level * 5;
}

void Orc::BellyFatAttack()
{
	int BellyFatAttackDamage = GetAttack() * 1.5;
	cout << GetName() << "�� ��� ����! ����� ���ڴ�.. ����� : " << BellyFatAttackDamage << endl;
}

void Orc::ClubAttack()
{
	int ClubAttackDamage = GetAttack() * 1.2;
	cout << GetName() << "�� ������ ����! ����� : " << ClubAttackDamage << endl;
}

void Orc::GroundShaking()
{
	int GroundShakingDamage = GetAttack() * 2;
	cout << GetName() << "�� ���︲!! ����� : " << GroundShakingDamage << endl;
}