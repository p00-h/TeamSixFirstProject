#pragma once
#include "Monster.h"
#include <string>

class Dragon : public Monster
{
	public:
		Dragon(int level);

		void FireBrass();
		void TailSwing();	//꼬리 공격
		void DeadlyCharge();	//치명적인돌격

		void NormalAttack() override;	//일반공격
		void UseSkill() override;	//랜덤 스킬
};