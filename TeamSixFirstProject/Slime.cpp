#include "Slime.h"
#include "Character.h"
#include <iostream>
using namespace std;

Slime::Slime(int level)
	:Monster("������", level)
{
	SetHP(GetHP() + 8);
	SetAttack(GetAttack() + 5);
	SetMP(0);
												//���� ���ʽ� ����� ��� ��
	//SlimeBouns = level * 5;
}

void Slime::StickyBall(Character* target)
{
	int StickyBallDamage = GetAttack() * 1.2;
	cout << GetName() << "�� ������ ��! ����� : " << StickyBallDamage << endl;
	if (target) target->SetHp(target->GetHp() - StickyBallDamage);
}

void Slime::MucusSpit(Character* target)
{
	int MucusSpitDamage = GetAttack() * 1.1;
	cout << GetName() << "�� ħ �b��! ����� : " << MucusSpitDamage << endl;
	if (target) target->SetHp(target->GetHp() - MucusSpitDamage);
}

void Slime::JumpAttack(Character* target)
{
	int JumpAttackDamage = GetAttack() * 1.4;
	cout << GetName() << "�� ���� ����, ����� : " << JumpAttackDamage << endl;
	if (target) target->SetHp(target->GetHp() - JumpAttackDamage);
}

void Slime::NormalAttack(Character* target)
{
	int Dmg = GetAttack();
	cout << GetName() << "�� �Ϲ� ����! ����� : " << Dmg << endl;
	//SetMP(GetMP() + 1);
}

void Slime::UseSkill(Character* target)
{
	int Choice = rand() % 3;
	if (Choice == 0) StickyBall(target);
	else if (Choice == 1) MucusSpit(target);
	else JumpAttack(target);

	//SetMP(0);
}