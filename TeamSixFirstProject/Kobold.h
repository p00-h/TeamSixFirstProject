#pragma once
#include "Monster.h"

#include "Character.h"

#include <string>

class Kobold : public Monster
{
	public:
		Kobold(int level);


		void PickaxeAttack(Character* target);	//곡괭이공격
		void OreThrow(Character* target); //광물 던지기
		void TramCarRush(Character* target);
		
//private:
//	int AttackBouns;	//레벨에 따른 보너스 정의

		void NormalAttack(Character* target) override;	//일반 공격
		void UseSkill(Character* target) override;	//랜덤 스킬

		//void BaseAttack();		//코볼트 일반 공격 정의, Kobold.cpp 줄 17구현
		
//private:
//	int AttackBouns;	//레벨에 따른 보너스 정의

};
