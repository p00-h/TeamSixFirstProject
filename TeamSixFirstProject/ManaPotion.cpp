#include "ManaPotion.h"
#include "Character.h"
#include <iostream>


ManaPotion::ManaPotion() : Item("¸¶³ª È¸º¹ Æ÷¼Ç",5, 10) {}

ManaPotion::ManaPotion() : Name("¸¶³ª È¸º¹ Æ÷¼Ç"), ManaRestore(10), Price(5) {}


bool ManaPotion::Use(Character* character) // ¾ÆÀÌÅÛ »ç¿ë
{
	if (character->GetMp() < character->GetMaxMp())
	{
		ItemSound();
		character->SetMp(character->GetMp() + Value);
		std::cout << character->GetName() << "ÀÇ ¸¶³ª°¡ " << Value << " È¸º¹ µÆ½À´Ï´Ù." << std::endl;
		return true;
	}
	else
	{
		std::cout << "ÀÌ¹Ì ¸¶³ª°¡ °¡µæ Ã¡½À´Ï´Ù." << std::endl;
		return false;
	}
}

std::string ManaPotion::ItemInfo() const // ¾ÆÀÌÅÛ Á¤º¸
{
	return "¸¶³ª¸¦ " + std::to_string(Value) + " È¸º¹ÇÕ´Ï´Ù.";
}

Item* ManaPotion::Clone() const // ¾ÆÀÌÅÛ º¹Á¦
{
	return new ManaPotion(*this);
}

bool ManaPotion::IsDurationBased() const // Áö¼ÓÇüÀÎÁö
{
	return false;
}
