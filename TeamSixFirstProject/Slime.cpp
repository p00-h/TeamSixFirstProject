#include "Slime.h"
#include <iostream>
using namespace std;

Slime::Slime(int level)
	:Monster("Slime", level)
{
	SetHP(GetHP() + 8);
	SetAttack(GetAttack() + 5);
	SetMP(0);
												//레벨 보너스 대미지 사용 시
	//SlimeBouns = level * 5;
}

void Slime::StickyBall()
{
	int StickyBallDamage = GetAttack() * 1.2;
	cout << GetName() << "의 끈끈이 공! 대미지 : " << StickyBallDamage << endl;
}

void Slime::MucusSpit()
{
	int MucusSpitDamage = GetAttack() * 1.1;
	cout << GetName() << "의 침 밷기! 대미지 : " << MucusSpitDamage << endl;
}

void Slime::JumpAttack()
{
	int JumpAttackDamage = GetAttack() * 1.4;
	cout << GetName() << "의 점프 공격, 대미지 : " << JumpAttackDamage << endl;
}

void Slime::NormalAttack()
{
	int Dmg = GetAttack();
	cout << GetName() << "의 일반 공격! 대미지 : " << Dmg << endl;
	SetMP(GetMP() + 1);
}

void Slime::UseSkill()
{
	int Choice = rand() % 3;
	if (Choice == 0) StickyBall();
	else if (Choice == 1) MucusSpit();
	else JumpAttack();

	SetMP(0);
}