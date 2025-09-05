#include "Slime.h"
#include <iostream>
using namespace std;

Slime::Slime(int level)
	:Monster("Slime", level)
{
	SetHP(GetHP() + 8);
	SetAttack(GetAttack() + 5);
	SetMP(0);
												//레벨 보너스 대미지 사용 시
	//SlimeBouns = level * 5;
}