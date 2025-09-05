#pragma once
#include "Monster.h"
#include <string>

class Golem : public Monster
{
	public:
		Golem(int level);

		//void Stomp();	//골렘 스톰프 스킬 정의, Golem.cpp의 줄18 구현
		
//private:
	//int StompBouns;		//레벨에 따른 대미지 보너스 정의
};
