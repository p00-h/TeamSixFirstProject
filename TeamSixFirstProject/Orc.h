#pragma once
#include "Monster.h"

class Orc : public Monster
{ 
	public:
		Orc(int level);

		void BellyFatAttack();	//뱃살 공격
		void ClubAttack(); //몽둥이 공격
		void GroundShaking();	//땅 울림

	//private:
	//	int OrcBouns;		//레벨 보너스 대미지 사용 시
};