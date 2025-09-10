#include "DefenseBoost.h"
#include "Character.h"
#include <iostream>


using namespace std;

DefenseBoost::DefenseBoost() : Name("¹æ¾î·Â Áõ°¡ Æ÷¼Ç"), DefenseIncrease(10),Price(15) {}


DefenseBoost::DefenseBoost() : Item("¹æ¾î·Â Áõ°¡ Æ÷¼Ç", 15, 10) {}

bool DefenseBoost::Use(Character* character) // ¾ÆÀÌÅÛ »ç¿ë
{
	if (IsActive)
	{
		cout << "ÀÌ¹Ì " << Name << "ÀÇ È¿°ú°¡ Àû¿ëÁßÀÔ´Ï´Ù." << endl;
		return false;
	}
	else
	{
		IsActive = true;
		ItemSound();
		character->SetDefense(character->GetDefense() + Value);
		cout << character->GetName() << "ÀÇ ¹æ¾î·ÂÀÌ " << Value << " Áõ°¡ÇÕ´Ï´Ù." << endl;
		return true;
	}
}

string DefenseBoost::ItemInfo() const // ¾ÆÀÌÅÛ Á¤º¸
{
	return "¹æ¾î·ÂÀÌ " + to_string(Value) + " Áõ°¡ÇÕ´Ï´Ù.";
}

Item* DefenseBoost::Clone() const // ¾ÆÀÌÅÛ º¹Á¦
{
	return new DefenseBoost(*this);
}

bool DefenseBoost::IsDurationBased() const // Áö¼ÓÇüÀÎÁö
{
	return true;
}

void DefenseBoost::EffectIsOver(Character* character)
{
	IsActive = false;
	cout << Name << "ÀÇ È¿°ú°¡ ³¡³µ½À´Ï´Ù." << endl;
	character->SetDefense(character->GetDefense() - Value);
}