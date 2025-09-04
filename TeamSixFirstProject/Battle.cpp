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
				cout << monster->GetName() << "���� " << player->GetPower << "��ŭ ���ظ� �������ϴ�.\n";
				cout << "���� ü��: " << monster->GetHP() << endl;
			}
			else
			{
				cout << "���͸� óġ�Ͽ����ϴ�.\n";
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
			cout << monster->GetName() << "���� " << monster->GetPower << "��ŭ ���ظ� �Ծ����ϴ�.\n";
			cout << "���� ü��: " << player->GetHP() << endl;
		}
		else
		{
			cout << "�÷��̾ �����Ͽ����ϴ�.\n";
			
			return;
		}
	}
}
