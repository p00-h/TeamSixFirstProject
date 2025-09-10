#include "Slime.h"
#include "Character.h"
#include <iostream>
using namespace std;

Slime::Slime(int level)
	:Monster("슬라임", level)
{
	SetHP(GetHP() + 8);
	SetAttack(GetAttack() + 5);
	SetMP(0);
												//레벨 보너스 대미지 사용 시
	//SlimeBouns = level * 5;
}

void Slime::StickyBall(Character* target)
{
	int StickyBallDamage = GetAttack() * 1.2;
	cout << GetName() << "의 끈끈이 공! 대미지 : " << StickyBallDamage << endl;
	if (target) target->SetHp(target->GetHp() - StickyBallDamage);
}

void Slime::MucusSpit(Character* target)
{
	int MucusSpitDamage = GetAttack() * 1.1;
	cout << GetName() << "의 침 밷기! 대미지 : " << MucusSpitDamage << endl;
	if (target) target->SetHp(target->GetHp() - MucusSpitDamage);
}

void Slime::JumpAttack(Character* target)
{
	int JumpAttackDamage = GetAttack() * 1.4;
	cout << GetName() << "의 점프 공격, 대미지 : " << JumpAttackDamage << endl;
	if (target) target->SetHp(target->GetHp() - JumpAttackDamage);
}

void Slime::NormalAttack(Character* target)
{
	int Dmg = GetAttack();
	cout << GetName() << "의 일반 공격! 대미지 : " << Dmg << endl;
	//SetMP(GetMP() + 1);
}

void Slime::UseSkill(Character* target)
{
	int Choice = rand() % 3;
	if (Choice == 0) StickyBall(target);
	else if (Choice == 1) MucusSpit(target);
	else JumpAttack(target);

	//SetMP(0);
}