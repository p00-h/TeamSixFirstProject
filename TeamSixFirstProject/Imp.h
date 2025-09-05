#pragma once
#include "Monster.h"

class Imp : public Monster
{
public:
	Imp(int level);

	void Magic();
	void SpiralIce(); //스파이럴 아이스
	void IceBolt();
	
//private:
//	int MagicBouns;		//레벨에 따른 대미지 보너스 정의
};