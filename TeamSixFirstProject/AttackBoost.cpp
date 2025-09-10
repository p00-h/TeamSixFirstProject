#include "AttackBoost.h"
#include "Character.h"
#include <iostream>


using namespace std;

AttackBoost::AttackBoost() : Name("°ø°Ý·Â Áõ°¡ Æ÷¼Ç"), AttackIncrease(10),Price(10) {}


AttackBoost::AttackBoost() : Item("°ø°Ý·Â Áõ°¡ Æ÷¼Ç", 10, 10) {}

bool AttackBoost::Use(Character* character) // ¾ÆÀÌÅÛ »ç¿ë
{
	if (IsActive) // ¾ÆÀÌÅÛ È¿°ú ÁßÃ¸ ¹æÁö
	{
		cout << "ÀÌ¹Ì " << Name << "ÀÇ È¿°ú°¡ Àû¿ëÁßÀÔ´Ï´Ù." << endl;
		return false;
	}
	else
	{
		IsActive = true;
		ItemSound();
		character->SetAttack(character->GetAttack() + Value);
		cout << character->GetName() << "ÀÇ °ø°Ý·ÂÀÌ " << Value << " Áõ°¡ÇÕ´Ï´Ù." << endl;
		return true;
	}
}

string AttackBoost::ItemInfo() const // ¾ÆÀÌÅÛ Á¤º¸
{
	return "°ø°Ý·ÂÀÌ " + to_string(Value) + " Áõ°¡ÇÕ´Ï´Ù.";
}

Item* AttackBoost::Clone() const // ¾ÆÀÌÅÛ º¹Á¦
{
	return new AttackBoost(*this);
}

bool AttackBoost::IsDurationBased() const // Áö¼ÓÇüÀÎÁö
{
	return true;
}

void AttackBoost::EffectIsOver(Character* character)
{
	IsActive = false;
	cout << Name << "ÀÇ È¿°ú°¡ ³¡³µ½À´Ï´Ù." << endl;
	character->SetAttack(character->GetAttack() - Value);
}