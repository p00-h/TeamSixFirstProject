#pragma once
#include "Monster.h"
#include "Character.h"

class Orc : public Monster
{ 
	public:
		Orc(int level);

		void BellyFatAttack(Character* target);	//뱃살 공격
		void ClubAttack(Character* target); //몽둥이 공격
		void GroundShaking(Character* target);	//땅 울림

	//private:
	//	int OrcBouns;		//레벨 보너스 대미지 사용 시
		
		void NormalAttack(Character* target) override;	//일반 공격
		void UseSkill(Character* target) override;	//랜덤 스킬
};