#include "Orc.h"
#include <iostream>
using namespace std;

Orc::Orc(int level)
	:Monster("Orc", level)
{
	SetHP(GetHP() + 20);
	SetAttack(GetAttack() + 10);
	SetMP(0);
										//레벨 보너스 대미지 사용 시
	//OrcBouns = level * 5;
}

void Orc::BellyFatAttack()
{
	int BellyFatAttackDamage = GetAttack() * 1.5;
	cout << GetName() << "의 뱃살 공격! 기분이 나쁘다.. 대미지 : " << BellyFatAttackDamage << endl;
}

void Orc::ClubAttack()
{
	int ClubAttackDamage = GetAttack() * 1.2;
	cout << GetName() << "의 몽둥이 공격! 대미지 : " << ClubAttackDamage << endl;
}

void Orc::GroundShaking()
{
	int GroundShakingDamage = GetAttack() * 2;
	cout << GetName() << "의 땅울림!! 대미지 : " << GroundShakingDamage << endl;
}