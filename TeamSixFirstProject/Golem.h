#pragma once
#include "Monster.h"
#include <string>

class Golem : public Monster
{
	public:
		Golem(int level);

		void Stomp(Character* target);
		void WindMill(Character* target);
		void SharpRock(Character* target);
		
//private:
	//int StompBouns;		//레벨에 따른 대미지 보너스 정의
		void NormalAttack(Character* target) override;	//일반 공격
		void UseSkill(Character* target) override;	//랜덤 스킬
};
