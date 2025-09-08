#pragma once
#include <iostream>
#include "Character.h"
#include "Monster.h"
#include "DirectionManager.h"
#include <vector>
#include <windows.h>

class Battle
{
public:
	Battle();
	void CharaterAttack(Character* character, Monster* monster);
	void MonsterAttack(Character* character, Monster* monster);
	int StartBattle(Character* character, Monster* monster);
	
};

