#include "Orc.h"
#include <iostream>

Orc::Orc(int level)
	:Monster("Orc", level)
{
	SetHP(GetHP() + 20);
	SetAttack(GetAttack() + 10);
	SetMP(0);
										//���� ���ʽ� ����� ��� ��
	//OrcBouns = level * 5;
}