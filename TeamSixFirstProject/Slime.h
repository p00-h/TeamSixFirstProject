#pragma once
#include "Monster.h"

class Slime : public Monster
{
	public:
		Slime(int level);

		void StickyBall(Character* target); //끈끈이 공
		void MucusSpit(Character* target); //침 밷기
		void JumpAttack(Character* target);

	//private:
	//	int SlimeBouns;	//레벨 보너스 대미지 사용 시
		void NormalAttack(Character* target) override;
		void UseSkill(Character* target) override;
};