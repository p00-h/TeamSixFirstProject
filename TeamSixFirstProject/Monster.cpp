#include "Monster.h"
using namespace std;

Monster::Monster(const string& n, int level)
{
	Name = n;
	//HP = rand() % (level * 30 - level * 20 + 1) + (level * 20);	//+1은 level =5 가정 150 - 100 + 1 = 51 rand()% 51이라고 가정 0~50 사이 값 + 100을 더함으로 레벨 비례 증가폭이 커짐
	HP = 10;	
	//Attack = rand() % (level * 10 - level * 5 + 1) + (level * 5);
	Attack = 10;	
}

void Monster::TakeDamage(int dmg)
{
	HP -= dmg;
	if (HP < 0) HP = 0;
}
bool Monster::IsDead()const
{
	return HP <= 0;
}
