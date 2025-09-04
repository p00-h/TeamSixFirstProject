#pragma once
#include "Monster.h"
#include <string>

class Kobold : public Monster
{
	public:
		Kobold(int level);

		//void BaseAttack();		//코볼트 일반 공격 정의, Kobold.cpp 줄 17구현
		
//private:
//	int AttackBouns;	//레벨에 따른 보너스 정의
};
