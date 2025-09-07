#pragma once
#include "Monster.h"
#include <string>

class Kobold : public Monster
{
	public:
		Kobold(int level);

		void PickaxeAttack();	//곡괭이공격
		void OreThrow(); //광물 던지기
		void TramCarRush();
		
//private:
//	int AttackBouns;	//레벨에 따른 보너스 정의

		void NormalAttack() override;	//일반 공격
		void UseSkill() override;	//랜덤 스킬
};
