#include "Orc.h"
#include <iostream>

Orc::Orc(int level)
	:Monster("Orc", level)
{
	SetHP(GetHP() + 20);
	SetAttack(GetAttack() + 10);
	SetMP(0);
										//레벨 보너스 대미지 사용 시
	//OrcBouns = level * 5;
}