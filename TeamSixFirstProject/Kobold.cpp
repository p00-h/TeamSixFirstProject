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
														//Kobold.h�� ���� ���ʽ� ����� ��� ��, Kobold.h �� 12����
	//AttackBouns = level * 2;
}

//void Kobold::BaseAttack()
//{
//	int KoboldDamage = GetAttack() + 5;										//���� ���ʽ� ����� ��� ���� ��
//	int KoboldDamage = GetAttack() + AttackBouns;				//���� ���ʽ� ����� ��� �� Kobodl.h �� 12 ����
//	cout << GetName() << "�� �Ϲ� ����, ����� : " << KoboldDamage << endl;
//}