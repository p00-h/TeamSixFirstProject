#include "DefenseBoost.h"
#include "Character.h"
#include <iostream>

using namespace std;

DefenseBoost::DefenseBoost() : Item("방어력 증가 포션", 15, 10, -1) {}

void DefenseBoost::Use(Character* character) // 아이템 사용
{
	if (Turn <= 0) // 아이템 효과 중첩 방지
	{
		ItemSound();
		Turn = 3;
		character->SetDefense(character->GetDefense() + Value);
		cout << character->GetName() << "의 방어력이 " << Turn << "턴 동안 " << Value << " 증가합니다." << endl;
	}
	else
	{
		cout << "이미 " << Name << "의 효과가 적용중입니다." << endl;
	}
}

string DefenseBoost::ItemInfo() const // 아이템 정보
{
	return "방어력이 " + to_string(Value) + " 증가합니다.";
}

Item* DefenseBoost::Clone() const // 아이템 복제
{
	return new DefenseBoost(*this);
}

void DefenseBoost::TurnDecrease(Character* character) // 턴 감소 후 아이템 효과 사라짐
{
	if (Turn < 0)
	{
		return;
	}

	if (Turn == 0)
	{
		character->SetDefense(character->GetDefense() - Value);
		cout << Name << "의 효과가 끝났습니다." << endl;
		Turn = -1;

	}
	else
	{
		cout << Name << "의 효과가 " << Turn << "턴 남았습니다." << endl;
	}
}