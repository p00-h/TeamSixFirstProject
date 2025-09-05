#include "Imp.h"
#include <iostream>
using namespace std;

Imp::Imp(int level)
	:Monster("Imp", level)
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

void Imp::Magic()
{
	int MagicDamage = GetAttack() * 1.2;							//레벨 보너스 대미지 사용 안할 시
//	int MagicDamage = GetAttack() + MagicBouns;			//레벨 보너스 대미지 사용 시 Imp.h 줄 14 정의
	cout << GetName() << "의 마법 스킬, 대미지 : " << MagicDamage << endl;
}

void Imp::SpiralIce()
{
	int SpiralIceDamage = GetAttack() * 1.4;
	cout << GetName() << "의 스파이럴 아이스! 대미지 : " << SpiralIceDamage << endl;
}

void Imp::IceBolt()
{
	int IceBoltDamage = GetAttack() * 1.3;
	cout << GetName() << "의 아이스 볼트! 대미지 : " << IceBoltDamage << endl;
}
