#pragma once
#include <iostream>
#include "Monster.h"

#ifdef DEBUG
#include <Windows.h>
#endif

class Player;

class BattleManager
{
public:
	BattleManager(Player* player, Monster* monster);
	static void AttackPlayer(Player* player, Monster* monster);
	static void AttackMonster(Player* player, Monster* monster);
	static void PlayerSkill(Player* player, Monster* monster);
};