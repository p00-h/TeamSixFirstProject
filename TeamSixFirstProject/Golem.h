#pragma once
#include "Monster.h"
#include <string>

class Golem : public Monster
{
	public:
		Golem(int level);

		void Stomp();
		void WindMill();
		void SharpRock();
		
//private:
	//int StompBouns;		//레벨에 따른 대미지 보너스 정의
		void NormalAttack() override;	//일반 공격
		void UseSkill() override;	//랜덤 스킬
};
