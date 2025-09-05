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
};
