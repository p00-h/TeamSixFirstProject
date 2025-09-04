#include "Battle.h"
#include "Character.h"
#include "Monster.h"
using namespace std;

Battle::Battle(Character* character, Monster* monster)
{
	while (true)
	{
		char Action;
		cin >> Action;
		switch (Action)
		{
		case 'a':
			monster->SetHP(monster->GetHP() - character->GetAttack());
			if (monster->GetHP() > 0)
			{
				cout << monster->GetName() << "에게 " << character->GetAttack() << "만큼 피해를 입혔습니다.\n";
				cout << "남은 체력: " << monster->GetHP() << endl;
			}
			else
			{
				cout << "몬스터를 처치하였습니다.\n";
				character->SetGold(character->GetGold() + 200);
				character->SetExp(character->GetExp() + 50);
				if (character->GetExp() >= 100)
				{
					character->SetLevel(character->GetLevel() + 1);
					character->SetExp(character->GetExp() - 100);
				}
				return;
			}
			break;
		default:
			break;
		}
		
		character->SetHP(character->GetHP() - monster->GetAttack());
		if (character->GetHP() > 0)
		{
			cout << monster->GetName() << "에게 " << monster->GetAttack() << "만큼 피해를 입었습니다.\n";
			cout << "남은 체력: " << character->GetHP() << endl;
		}
		else
		{
			cout << "플레이어가 기절하였습니다.\n";
			
			return;
		}
	}
}
