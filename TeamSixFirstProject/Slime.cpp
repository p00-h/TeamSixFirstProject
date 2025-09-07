#include "Slime.h"
#include <iostream>
using namespace std;

Slime::Slime(int level)
	:Monster("Slime", level)
{
	SetHP(GetHP() + 8);
	SetAttack(GetAttack() + 5);
	SetMP(0);
												//���� ���ʽ� ����� ��� ��
	//SlimeBouns = level * 5;
}

void Slime::StickyBall()
{
	int StickyBallDamage = GetAttack() * 1.2;
	cout << GetName() << "�� ������ ��! ����� : " << StickyBallDamage << endl;
}

void Slime::MucusSpit()
{
	int MucusSpitDamage = GetAttack() * 1.1;
	cout << GetName() << "�� ħ �b��! ����� : " << MucusSpitDamage << endl;
}

void Slime::JumpAttack()
{
	int JumpAttackDamage = GetAttack() * 1.4;
	cout << GetName() << "�� ���� ����, ����� : " << JumpAttackDamage << endl;
}

void Slime::NormalAttack()
{
	int Dmg = GetAttack();
	cout << GetName() << "�� �Ϲ� ����! ����� : " << Dmg << endl;
	SetMP(GetMP() + 1);
}

void Slime::UseSkill()
{
	int Choice = rand() % 3;
	if (Choice == 0) StickyBall();
	else if (Choice == 1) MucusSpit();
	else JumpAttack();

	SetMP(0);
}