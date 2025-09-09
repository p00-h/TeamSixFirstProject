#include "AttackBoost.h"
#include "Character.h"
#include <iostream>

using namespace std;

AttackBoost::AttackBoost() : Item("공격력 증가 포션", 10, 10, -1) {}

void AttackBoost::Use(Character* character) // 아이템 사용
{
	if (Turn <= 0) // 아이템 효과 중첩 방지
	{
		ItemSound();
		Turn = 3;
		character->SetAttack(character->GetAttack() + Value);
		cout << character->GetName() << "의 공격력이 " << Turn << "턴 동안 " << Value << " 증가합니다." << endl;
	}
	else
	{
		cout << "이미 " << Name << "의 효과가 적용중입니다." << endl;
	}
}

string AttackBoost::ItemInfo() const // 아이템 정보
{
	return "공격력이 " + to_string(Value) + " 증가합니다.";
}

Item* AttackBoost::Clone() const // 아이템 복제
{
	return new AttackBoost(*this);
}

void AttackBoost::TurnDecrease(Character* character) // 턴 감소 후 아이템 효과 사라짐
{
	if(Turn < 0)
	{
		return;
	}

	if (Turn == 0)
	{
		character->SetAttack(character->GetAttack() - Value);
		cout << Name << "의 효과가 끝났습니다." << endl;

	}
	else
	{
		cout << Name << "의 효과가 " << Turn << "턴 남았습니다." << endl;
	}
}