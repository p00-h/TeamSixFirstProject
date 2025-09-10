#pragma once
#include <iostream>
#include "Character.h"
#include "Monster.h"
#include "DirectionManager.h"
#include <vector>
#include <windows.h>
#include <queue>
#include <mmsystem.h>

class Battle
{
public:
	Battle();
	void SetColor(int color);
	void SetColorDefault();
	void CharaterAttack(Character* character, Monster* monster);
	int ShowBattel(Monster* monster, Character* character, int& monsterhp, const int& monstermp);
	void MonsterAttack(Character* character, Monster* monster);
	int StartBattle(Character* character, Monster* monster);
};

