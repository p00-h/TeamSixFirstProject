#include "Golem.h"
#include <iostream>
using namespace std;

Golem::Golem(int level)
	:Monster("Golem", level)
{												//Monster.h�� HP�� Attack�� private�� �����ϸ鼭 ���� ����
	SetHP(GetHP()+50);	
	SetAttack(GetAttack() + 15);
												//Monster.h��  HP�� Attack�� protected ��� ��
	//HP += 50;
	//Attack += 15;
												//Golem.cpp�� ���� ���ʽ� ����� ��� �� ,Golem.h �� 12 ����
	//StompBouns = level * 5;
}

//void Golem::Stomp()															//Golem.h�� ��10 ����
//{
//	int StompDamage = GetAttack() + 30;						// �������ʽ� ����� ��� ���� ��
// 	int StompDamage = GetAttack() + StompBouns;		//�������ʽ� ����� ��� �� Golem.h �� 12 ����
//	cout << GetName() << "�� ������ ��ų ����! ����� : " << StompDamage << endl;
//}
