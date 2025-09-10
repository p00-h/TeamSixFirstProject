#pragma once
#include "Monster.h"
#include "Character.h"

class Imp : public Monster
{
public:
	Imp(int level);

	void Magic(Character* target);
	void SpiralIce(Character* target); //스파이럴 아이스
	void IceBolt(Character* target);
	
//private:
//	int MagicBouns;		//레벨에 따른 대미지 보너스 정의
	void NormalAttack(Character* target) override;	//일반 공격
	void UseSkill(Character* target) override;	//랜덤 스킬
};