#include "DefenseBoost.h"
#include "Character.h"
#include <iostream>

using namespace std;

DefenseBoost::DefenseBoost() : Item("방어력 증가 포션", 15, 10) {}

bool DefenseBoost::Use(Character* character) // 아이템 사용
{
	if (IsActive)
	{
		cout << "이미 " << Name << "의 효과가 적용중입니다." << endl;
		return false;
	}
	else
	{
		IsActive = true;
		ItemSound();
		character->SetDefense(character->GetDefense() + Value);
		cout << character->GetName() << "의 방어력이 " << Value << " 증가합니다." << endl;
		return true;
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

bool DefenseBoost::IsDurationBased() const // 지속형인지
{
	return true;
}
