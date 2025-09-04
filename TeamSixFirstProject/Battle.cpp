#include "Battle.h"
using namespace std;

Battle::Battle(Player* player, Monster* monster)
{
	while (true)
	{
		char Action;
		cin >> Action;
		switch (Action)
		{
		case 'a':
			player->Attack(monster);
			if (monster->GetHP() > 0)
			{
				cout << monster->GetName() << "에게 " << player->GetPower << "만큼 피해를 입혔습니다.\n";
				cout << "남은 체력: " << monster->GetHP() << endl;
			}
			else
			{
				cout << "몬스터를 처치하였습니다.\n";
				player->SetGold(player->GetGold() + 200);
				player->SetExp(player->GetExp() + 50);
				if (player->GetExp() >= 100)
				{
					player->SetLevel(player->GetLevel() + 1);
					player->SetExp(player->GetExp() - 100);
				}
				return;
			}
			break;
		default:
			break;
		}
		monster->TakeDamege(player);
		if (player->GetHP() > 0)
		{
			cout << monster->GetName() << "에게 " << monster->GetPower << "만큼 피해를 입었습니다.\n";
			cout << "남은 체력: " << player->GetHP() << endl;
		}
		else
		{
			cout << "플레이어가 기절하였습니다.\n";
			
			return;
		}
	}
}
