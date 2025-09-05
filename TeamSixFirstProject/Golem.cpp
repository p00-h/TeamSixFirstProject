#include "Golem.h"
#include <iostream>
using namespace std;

Golem::Golem(int level)
	:Monster("Golem", level)
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

void Golem::Stomp()															//Golem.h�� ��10 ����
{
	int StompDamage = GetAttack() * 2;						// �������ʽ� ����� ��� ���� ��
// 	int StompDamage = GetAttack() + StompBouns;		//�������ʽ� ����� ��� �� Golem.h �� 14����
	cout << GetName() << "�� ������ ��ų ����! ����� : " << StompDamage << endl;
}

void Golem::WindMill()
{
	int WindMillDamage = GetAttack() * 1.2;
	cout << GetName() << "�� �ȵ�� ��ų ����! ����� : " << WindMillDamage << endl;
}

void Golem::SharpRock()
{
	int SharpRockDamage = GetAttack() * 2.5;
	cout << GetName() << "�� ��ī�ο� ���� ����! ����� : " << SharpRockDamage << endl;
}
