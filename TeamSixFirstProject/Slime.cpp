#include "Slime.h"
#include <iostream>
using namespace std;

Slime::Slime(int level)
	:Monster("Slime", level)
{
	SetHP(GetHP() + 8);
	SetAttack(GetAttack() + 5);
	SetMP(0);
												//���� ���ʽ� ����� ��� ��
	//SlimeBouns = level * 5;
}