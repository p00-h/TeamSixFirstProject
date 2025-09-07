#pragma once
#include "Monster.h"

class Slime : public Monster
{
	public:
		Slime(int level);

		void StickyBall(); //끈끈이 공
		void MucusSpit(); //침 밷기
		void JumpAttack();

	//private:
	//	int SlimeBouns;	//레벨 보너스 대미지 사용 시
		void NormalAttack() override;
		void UseSkill() override;
};