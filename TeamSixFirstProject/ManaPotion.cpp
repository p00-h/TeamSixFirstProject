#include "ManaPotion.h"

<<<<<<< HEAD
ManaPotion::ManaPotion() : Name("���� ȸ�� ����"), ManaRestore(10), Price(5) {}

std::string ManaPotion::GetName()
{
    return Name;
}

void ManaPotion::Use(Character* character)
{
=======
ManaPotion::ManaPotion() : Item("���� ȸ�� ����",5, 10) {}

bool ManaPotion::Use(Character* character) // ������ ���
{
	if (character->GetMp() < character->GetMaxMp())
	{
		ItemSound();
		character->SetMp(character->GetMp() + Value);
		std::cout << character->GetName() << "�� ������ " << Value << " ȸ�� �ƽ��ϴ�." << std::endl;
		return true;
	}
	else
	{
		std::cout << "�̹� ������ ���� á���ϴ�." << std::endl;
		return false;
	}
}

std::string ManaPotion::ItemInfo() const // ������ ����
{
	return "������ " + std::to_string(Value) + " ȸ���մϴ�.";
}

Item* ManaPotion::Clone() const // ������ ����
{
	return new ManaPotion(*this);
}

bool ManaPotion::IsDurationBased() const // ����������
{
	return false;
>>>>>>> parent of 5e63b35 (Merge branch 'main' into dev)
}
