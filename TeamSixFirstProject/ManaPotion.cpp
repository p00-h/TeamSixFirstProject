#include "ManaPotion.h"
#include "Character.h"
#include <iostream>

ManaPotion::ManaPotion() : Item("���� ȸ�� ����",5, 10) {}

void ManaPotion::Use(Character* character)
{
	character->SetMp(character->GetMp() + Value);
	std::cout << character->GetName() << "�� ������ " << Value << " ȸ�� �ƽ��ϴ�." << std::endl;
}

void ManaPotion::ItemInfo()
{
	std::cout << "������ " << Value << " ȸ���մϴ�." << std::endl;
}
