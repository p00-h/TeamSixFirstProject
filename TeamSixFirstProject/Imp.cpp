#include "Imp.h"
#include <iostream>
using namespace std;

Imp::Imp(int level)
	:Monster("Imp", level)
{													//Monster.h�� HP�� Attack�� private�� �����ϸ鼭 ���� ����
	SetHP(GetHP() + 5);
	SetAttack(GetAttack() + 4);
	SetMP(0);
													//Monster.h��  HP�� Attack�� protected ��� ��
	//HP += 5;
	//Attack += 4;											
													//���� ���ʽ� ����� ��� �� ,Imp.h �� 14 ����
	//MagicBouns = level * 5;
}

void Imp::Magic()
{
	int MagicDamage = GetAttack() * 1.2;							//���� ���ʽ� ����� ��� ���� ��
//	int MagicDamage = GetAttack() + MagicBouns;			//���� ���ʽ� ����� ��� �� Imp.h �� 14 ����
	cout << GetName() << "�� ���� ��ų, ����� : " << MagicDamage << endl;
}

void Imp::SpiralIce()
{
	int SpiralIceDamage = GetAttack() * 1.4;
	cout << GetName() << "�� �����̷� ���̽�! ����� : " << SpiralIceDamage << endl;
}

void Imp::IceBolt()
{
	int IceBoltDamage = GetAttack() * 1.3;
	cout << GetName() << "�� ���̽� ��Ʈ! ����� : " << IceBoltDamage << endl;
}
