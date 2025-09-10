#include "HealthPotion.h"
#include "Character.h"
#include <iostream>


HealthPotion::HealthPotion() : Item("체력 회복 포션", 5, 50) {}

HealthPotion::HealthPotion() : Name("체력 회복 포션"), HealthRestore(50),Price(5) {}


bool HealthPotion::Use(Character* character) // 아이템 사용
{
	if (character->GetHp() < character->GetMaxHp())
	{
		ItemSound();
		character->SetHp(character->GetHp() + Value);
		std::cout << character->GetName() << "의 체력이 " << Value << " 회복 됐습니다." << std::endl;
		return true;
	}
	else
	{
		std::cout << "이미 체력이 가득 찼습니다." << std::endl;
		return false;
	}
}

std::string HealthPotion::ItemInfo() const // 아이템 정보
{
	return "체력을 " + std::to_string(Value) + " 회복합니다.";
}

Item* HealthPotion::Clone() const // 아이템 복제
{
	return new HealthPotion(*this);
}

bool HealthPotion::IsDurationBased() const // 지속형인지
{
	return false;
}
