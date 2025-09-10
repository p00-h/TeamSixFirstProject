#include "Imp.h"
#include <iostream>
using namespace std;

Imp::Imp(int level)
	:Monster("����", level)
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

void Imp::Magic(Character* target)
{
	int MagicDamage = GetAttack() * 1.2;							//���� ���ʽ� ����� ��� ���� ��
//	int MagicDamage = GetAttack() + MagicBouns;			//���� ���ʽ� ����� ��� �� Imp.h �� 14 ����
	cout << GetName() << "�� ���� ��ų, ����� : " << MagicDamage << endl;
	if (target) target->SetHp(target->GetHp() - MagicDamage);
}

void Imp::SpiralIce(Character* target)
{
	int SpiralIceDamage = GetAttack() * 1.4;
	cout << GetName() << "�� �����̷� ���̽�! ����� : " << SpiralIceDamage << endl;
	if (target) target->SetHp(target->GetHp() - SpiralIceDamage);
}

void Imp::IceBolt(Character* target)
{
	int IceBoltDamage = GetAttack() * 1.3;
	cout << GetName() << "�� ���̽� ��Ʈ! ����� : " << IceBoltDamage << endl;
	if (target) target->SetHp(target->GetHp() - IceBoltDamage);
}

void Imp::NormalAttack(Character* target)
{
	int Dmg = GetAttack();
	cout << GetName() << "�� �Ϲ� ����! �����: " << Dmg << endl;
	//SetMP(GetMP() + 1); //�Ϲ� ������ �� ����+1
}

void Imp::UseSkill(Character* target)
{
	int Choice = rand() % 3;	//0~2 �� �ϳ�
	if (Choice == 0) Magic(target);
	else if (Choice == 1) SpiralIce(target);
	else IceBolt(target);

	//SetMP(0);	//��ų ��� �� ���� �ʱ�ȭ
}