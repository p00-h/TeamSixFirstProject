#include "ManaPotion.h"

<<<<<<< HEAD
ManaPotion::ManaPotion() : Name("마나 회복 포션"), ManaRestore(10), Price(5) {}

std::string ManaPotion::GetName()
{
    return Name;
}

void ManaPotion::Use(Character* character)
{
=======
ManaPotion::ManaPotion() : Item("마나 회복 포션",5, 10) {}

bool ManaPotion::Use(Character* character) // 아이템 사용
{
	if (character->GetMp() < character->GetMaxMp())
	{
		ItemSound();
		character->SetMp(character->GetMp() + Value);
		std::cout << character->GetName() << "의 마나가 " << Value << " 회복 됐습니다." << std::endl;
		return true;
	}
	else
	{
		std::cout << "이미 마나가 가득 찼습니다." << std::endl;
		return false;
	}
}

std::string ManaPotion::ItemInfo() const // 아이템 정보
{
	return "마나를 " + std::to_string(Value) + " 회복합니다.";
}

Item* ManaPotion::Clone() const // 아이템 복제
{
	return new ManaPotion(*this);
}

bool ManaPotion::IsDurationBased() const // 지속형인지
{
	return false;
>>>>>>> parent of 5e63b35 (Merge branch 'main' into dev)
}
