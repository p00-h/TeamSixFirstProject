#include "ManaPotion.h"
#include "Character.h"
#include <iostream>

ManaPotion::ManaPotion() : Item("���� ȸ�� ����",5, 10) {}

void ManaPotion::Use(Character* character)
{
	character->SetMp(character->GetMp() + Value);
	std::cout << character->GetName() << "�� ������ " << Value << " ȸ�� �ƽ��ϴ�." << std::endl;
}

std::string ManaPotion::ItemInfo()
{
	return "������ " + std::to_string(Value) + " ȸ���մϴ�.";
}

Item* ManaPotion::Clone() const
{
	return new ManaPotion(*this);
}