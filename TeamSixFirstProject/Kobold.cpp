#include "Kobold.h"
#include <iostream>
using namespace std;

Kobold::Kobold(int level)
	:Monster("코볼트", level)
{														//Monster.h의 HP와 Attack을 private를 유지하면서 수정 가능
	SetHP(GetHP() + 10);
	SetAttack(GetAttack() + 2);
	SetMP(0);
														//Monster.h의  HP와 Attack을 protected 사용 시
	//HP += 10;
	//Attack += 15;
														//Kobold.h의 레벨 보너스 대미지 사용 시, Kobold.h 줄 14정의
	//AttackBouns = level * 2;
}

void Kobold::PickaxeAttack(Character* target)
{
	int PickaxeAttackDamage = GetAttack() * 1.2;										//레벨 보너스 대미지 사용 안할 시
//	int KoboldDamage = GetAttack() + AttackBouns;				//레벨 보너스 대미지 사용 시 Kobodl.h 줄 14 정의
	cout << GetName() << "의 일반 공격, 대미지 : " << PickaxeAttackDamage << endl;
	if (target) target->SetHp(target->GetHp() - PickaxeAttackDamage);
}

void Kobold::OreThrow(Character* target)
{
	int OreThrowDamage = GetAttack() * 1.4;
	cout << GetName() << "의 광물 던진기, 대미지 : " << OreThrowDamage << endl;
	if (target) target->SetHp(target->GetHp() - OreThrowDamage);
}

void Kobold::TramCarRush(Character* target)
{
	int TramCarRushDamage = GetAttack() * 1.8;
	cout << GetName() << "의 광차 러쉬! 대미지 : " << TramCarRushDamage << endl;
	if (target) target->SetHp(target->GetHp() - TramCarRushDamage);
}

void Kobold::NormalAttack(Character* target)
{
	int Dmg = GetAttack();
	cout << GetName() << "의 일반 공격! 대미지 : " << Dmg << endl;
	//SetMP(GetMP() + 1);	//일반 공격할 때 마나+1
}

void Kobold::UseSkill(Character* target)
{
	int Choice = rand() % 3;	//0~2 중 하나
	if (Choice == 0) PickaxeAttack(target);
	else if (Choice == 1)OreThrow(target);
	else TramCarRush(target);

	//SetMP(0);	//스킬 사용 후 마나 초기화
}
