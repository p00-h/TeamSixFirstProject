#include "Dragon.h"
#include <iostream>
using namespace std;

Dragon::Dragon(int level)
	:Monster("Dragon", level)
{
	SetHP(GetHP() + 100);
	SetAttack(GetAttack() + 40);
	SetMP(0);
}

void Dragon::FireBrass()
{
	int FireBrassDamage = GetAttack() * 1.5;
	cout << " 대기의 공기가 뜨거워지기 시작했다.\n"
		<< GetName() << "의 파이어브래스! 대미지 : " << FireBrassDamage << endl;
}

void Dragon::TailSwing()
{
	int TailSwingDamage = GetAttack() * 1.2;
	cout << GetName() << "의 위협적인 꼬리 공격! 대미지 : " << TailSwingDamage << endl;
}

void Dragon::DeadlyCharge()
{
	int DeadlyCharg = GetAttack() * 1.4;
	cout << GetName() << "의 돌진 공격이다! 대미지 : " << DeadlyCharg << endl;
}

void Dragon::NormalAttack()
{
	int Dmg = GetAttack();
	cout << GetName() << "의 일반 공격! 대미지 : " << Dmg << endl;
	//SetMP(GetMP() + 1);	//일반 공격할 때 마나+1
}

void Dragon::UseSkill()
{
	int Choice = rand() % 3;	//랜덤 스킬 0~2중 하나
	if (Choice == 0) FireBrass();
	else if (Choice == 1) TailSwing();
	else DeadlyCharge();
	//SetMP(0); //스킬 사용 후 마나 초기화.
}