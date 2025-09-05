#include "ManaPotion.h"
#include "Character.h"
#include <iostream>

ManaPotion::ManaPotion() : Item("���� ȸ�� ����",5), ManaRestore(10) {}

void ManaPotion::Use(Character* character)
{
	character->SetMp(character->GetMp() + ManaRestore);
	std::cout << character->GetName() << "�� ������ " << ManaRestore << " ȸ�� �ƽ��ϴ�." << std::endl;
}
