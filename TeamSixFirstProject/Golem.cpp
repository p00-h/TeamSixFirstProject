#include "Golem.h"
#include <iostream>
using namespace std;

Golem::Golem(int level)
	:Monster("Golem", level)
{												//Monster.h의 HP와 Attack을 private를 유지하면서 수정 가능
	SetHP(GetHP()+50);	
	SetAttack(GetAttack() + 15);
	SetMP(0);
												//Monster.h의  HP와 Attack을 protected 사용 시
	//HP += 50;
	//Attack += 15;
												//Golem.cpp의 레벨 보너스 대미지 사용 시 ,Golem.h 줄 14 정의
	//StompBouns = level * 5;
}

void Golem::Stomp()															//Golem.h의 줄10 정의
{
	int StompDamage = GetAttack() * 2;						// 레벨보너스 대미지 사용 안할 시
// 	int StompDamage = GetAttack() + StompBouns;		//레벨보너스 대미지 사용 시 Golem.h 줄 14정의
	cout << GetName() << "의 스톰프 스킬 공격! 대미지 : " << StompDamage << endl;
}

void Golem::WindMill()
{
	int WindMillDamage = GetAttack() * 1.2;
	cout << GetName() << "의 읜드밀 스킬 공격! 대미지 : " << WindMillDamage << endl;
}

void Golem::SharpRock()
{
	int SharpRockDamage = GetAttack() * 2.5;
	cout << GetName() << "의 날카로운 바위 공격! 대미지 : " << SharpRockDamage << endl;
}
