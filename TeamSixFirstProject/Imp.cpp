#include "Imp.h"
#include <iostream>
using namespace std;

Imp::Imp(int level)
	:Monster("Imp", level)
{													//Monster.h�� HP�� Attack�� private�� �����ϸ鼭 ���� ����
	SetHP(GetHP() + 5);
	SetAttack(GetAttack() + 4);
													//Monster.h��  HP�� Attack�� protected ��� ��
	//HP += 5;
	//Attack += 4;											
													//���� ���ʽ� ����� ��� �� ,Imp.h �� 11 ����
	//MagicBouns = level * 5;
}

//void Imp::Magic()
//{
//	int MagicDamage = GetAttack() +  15;							//���� ���ʽ� ����� ��� ���� ��
//	int MagicDamage = GetAttack() + MagicBouns;			//���� ���ʽ� ����� ��� �� Imp.h �� 11 ����
//	cout << GetName() << "�� ���� ��ų, ����� : " << MagicDamage << endl;
//}