#include "Kobold.h"
#include <iostream>
using namespace std;

Kobold::Kobold(int level)
	:Monster("Kobold", level)
{														//Monster.h의 HP와 Attack을 private를 유지하면서 수정 가능
	SetHP(GetHP() + 10);
	SetAttack(GetAttack() + 2);
	SetMP(0);
														//Monster.h의  HP와 Attack을 protected 사용 시
	//HP += 10;
	//Attack += 15;
														//Kobold.h의 레벨 보너스 대미지 사용 시, Kobold.h 줄 12정의
	//AttackBouns = level * 2;
}

//void Kobold::BaseAttack()
//{
//	int KoboldDamage = GetAttack() + 5;										//레벨 보너스 대미지 사용 안할 시
//	int KoboldDamage = GetAttack() + AttackBouns;				//레벨 보너스 대미지 사용 시 Kobodl.h 줄 12 정의
//	cout << GetName() << "의 일반 공격, 대미지 : " << KoboldDamage << endl;
//}