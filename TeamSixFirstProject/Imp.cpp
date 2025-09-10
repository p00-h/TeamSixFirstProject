#include "Imp.h"
#include <iostream>
using namespace std;

Imp::Imp(int level)
	:Monster("임프", level)
{													//Monster.h의 HP와 Attack을 private를 유지하면서 수정 가능
	SetHP(GetHP() + 5);
	SetAttack(GetAttack() + 4);
	SetMP(0);
													//Monster.h의  HP와 Attack을 protected 사용 시
	//HP += 5;
	//Attack += 4;											
													//레벨 보너스 대미지 사용 시 ,Imp.h 줄 14 정의
	//MagicBouns = level * 5;
}

void Imp::Magic(Character* target)
{
	int MagicDamage = GetAttack() * 1.2;							//레벨 보너스 대미지 사용 안할 시
//	int MagicDamage = GetAttack() + MagicBouns;			//레벨 보너스 대미지 사용 시 Imp.h 줄 14 정의
	cout << GetName() << "의 마법 스킬, 대미지 : " << MagicDamage << endl;
	if (target) target->SetHp(target->GetHp() - MagicDamage);
}

void Imp::SpiralIce(Character* target)
{
	int SpiralIceDamage = GetAttack() * 1.4;
	cout << GetName() << "의 스파이럴 아이스! 대미지 : " << SpiralIceDamage << endl;
	if (target) target->SetHp(target->GetHp() - SpiralIceDamage);
}

void Imp::IceBolt(Character* target)
{
	int IceBoltDamage = GetAttack() * 1.3;
	cout << GetName() << "의 아이스 볼트! 대미지 : " << IceBoltDamage << endl;
	if (target) target->SetHp(target->GetHp() - IceBoltDamage);
}

void Imp::NormalAttack(Character* target)
{
	int Dmg = GetAttack();
	cout << GetName() << "의 일반 공격! 대미지: " << Dmg << endl;
	//SetMP(GetMP() + 1); //일반 공격할 때 마나+1
}

void Imp::UseSkill(Character* target)
{
	int Choice = rand() % 3;	//0~2 중 하나
	if (Choice == 0) Magic(target);
	else if (Choice == 1) SpiralIce(target);
	else IceBolt(target);

	//SetMP(0);	//스킬 사용 후 마나 초기화
}