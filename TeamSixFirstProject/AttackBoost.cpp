#include "AttackBoost.h"

<<<<<<< HEAD
AttackBoost::AttackBoost() : Name("공격력 증가 포션"), AttackIncrease(10),Price(10) {}

std::string AttackBoost::GetName()
{
    return Name;
}

void AttackBoost::Use(Character* character)
{
}
=======
using namespace std;

AttackBoost::AttackBoost() : Item("공격력 증가 포션", 10, 10) {}

bool AttackBoost::Use(Character* character) // 아이템 사용
{
	if (IsActive) // 아이템 효과 중첩 방지
	{
		cout << "이미 " << Name << "의 효과가 적용중입니다." << endl;
		return false;
	}
	else
	{
		IsActive = true;
		ItemSound();
		character->SetAttack(character->GetAttack() + Value);
		cout << character->GetName() << "의 공격력이 " << Value << " 증가합니다." << endl;
		return true;
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

bool AttackBoost::IsDurationBased() const // 지속형인지
{
	return true;
}

void AttackBoost::EffectIsOver(Character* character)
{
	IsActive = false;
	cout << Name << "의 효과가 끝났습니다." << endl;
	character->SetAttack(character->GetAttack() - Value);
}
>>>>>>> parent of 5e63b35 (Merge branch 'main' into dev)
