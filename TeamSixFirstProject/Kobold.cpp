#include "Kobold.h"

Kobold::Kobold(int level)
	:Monster("Kobold", level)
{														//Monster.h�� HP�� Attack�� private�� �����ϸ鼭 ���� ����
	SetHP(GetHP() + 10);
	SetAttack(GetAttack() + 2);
														//Monster.h��  HP�� Attack�� protected ��� ��
	//HP += 10;
	//Attack += 15;
														//Kobold.h�� ���� ���ʽ� ����� ��� ��, Kobold.h �� 11����
	//AttackBouns = level * 2;
}