#include "Kobold.h"

Kobold::Kobold(int level)
	:Monster("Kobold", level)
{														//Monster.h의 HP와 Attack을 private를 유지하면서 수정 가능
	SetHP(GetHP() + 10);
	SetAttack(GetAttack() + 2);
														//Monster.h의  HP와 Attack을 protected 사용 시
	//HP += 10;
	//Attack += 15;
														//Kobold.h의 레벨 보너스 대미지 사용 시, Kobold.h 줄 11정의
	//AttackBouns = level * 2;
}