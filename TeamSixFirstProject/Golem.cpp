#include "Golem.h"
#include "Character.h"
#include <iostream>
using namespace std;

Golem::Golem(int level)
	:Monster("��", level)
{												//Monster.h�� HP�� Attack�� private�� �����ϸ鼭 ���� ����
	SetHP(GetHP()+50);	
	SetAttack(GetAttack() + 15);
	SetMP(0);
												//Monster.h��  HP�� Attack�� protected ��� ��
	//HP += 50;
	//Attack += 15;
												//Golem.cpp�� ���� ���ʽ� ����� ��� �� ,Golem.h �� 14 ����
	//StompBouns = level * 5;
}

void Golem::Stomp(Character* target)															//Golem.h�� ��10 ����
{
	int StompDamage = GetAttack() * 2;						// �������ʽ� ����� ��� ���� ��
// 	int StompDamage = GetAttack() + StompBouns;		//�������ʽ� ����� ��� �� Golem.h �� 14����
	cout << GetName() << "�� ������ ��ų ����! ����� : " << StompDamage << endl;
	if (target) target->SetHp(target->GetHp() - StompDamage);
}

void Golem::WindMill(Character* target)
{
	int WindMillDamage = GetAttack() * 1.2;
	cout << GetName() << "�� �ȵ�� ��ų ����! ����� : " << WindMillDamage << endl;
	if (target) target->SetHp(target->GetHp() - WindMillDamage);
}

void Golem::SharpRock(Character* target)
{
	int SharpRockDamage = GetAttack() * 2.5;
	cout << GetName() << "�� ��ī�ο� ���� ����! ����� : " << SharpRockDamage << endl;
	if (target) target->SetHp(target->GetHp() - SharpRockDamage);
}

void Golem::NormalAttack(Character* target)
{
	int Dmg = GetAttack();
	cout << GetName() << "�� �Ϲ� ����! �����: " << Dmg << endl;
	//SetMP(GetMP() + 1);	//�Ϲ� ������ �� ���� +1
}

void Golem::UseSkill(Character* target)
{
	int Choice = rand() % 3;	//0~2 �� �ϳ�
	if (Choice == 0) Stomp(target);
	else if (Choice == 1) WindMill(target);
	else SharpRock(target);

	//SetMP(0);	//��ų ��� �� ���� �ʱ�ȭ
}
