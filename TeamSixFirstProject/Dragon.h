#pragma once
#include "Monster.h"
#include <string>

class Dragon : public Monster
{
	public:
		Dragon(int level);

		void FireBrass(Character* target);
		void TailSwing(Character* target);	//꼬리 공격
		void DeadlyCharge(Character* target);	//치명적인돌격

		void NormalAttack(Character* target) override;	//일반공격
		void UseSkill(Character* target) override;	//랜덤 스킬
};