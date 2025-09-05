#pragma once
#include "Monster.h"

class Imp : public Monster
{
public:
	Imp(int level);

	//void Magic();		//임프 마법 스킬 정의, Imp.cpp 줄 18 구현
	
//private:
//	int MagicBouns;		//레벨에 따른 대미지 보너스 정의
};