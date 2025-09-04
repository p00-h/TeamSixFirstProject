#include "BattleManager.h"
#include "GameManager.h"
#include <SFML/Graphics.hpp>

#include <conio.h>
#ifdef _WIN32
#include <Windows.h>
#endif

using namespace std;
BattleManager::BattleManager(Player* player, Monster* monster)
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif // DEBUG
	const char* action[] = { "����" , "����" };
	int sel = 0;
	while (true)
	{
		for (int i = 0; i < 2; i++)
		{
			if (i == sel) cout << "> " << action[i] << endl;
			else cout << "  " << action[i] << endl;
		}
		int key = _getch();
		if (key == 224)
		{
			key = _getch();
			if (key == 72)
			{
				sel = (sel - 1 )
			}
		}
		switch ()
		{
		case 'a':
			AttackPlayer(player, monster);
			break;

		case 's':

			break;
		default:
			break;
		}
		//monster->TakeDamege(player);
		AttackMonster(player, monster);
	}
}

void BattleManager::AttackPlayer(Player* player, Monster* monster)
{
	monster->SetHP(monster->GetHP() - player->GeyAttack());
	if (monster->GetHP() > 0)
	{
		cout << monster->GetName() << "���� " << player->GetAttack() << "��ŭ ���ظ� �������ϴ�.\n";
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
}

void BattleManager::AttackMonster(Player* player, Monster* monster)
{
	player->SetHP(player->GetHP() - monster->GetAttack());
	if (player->GetHP() > 0)
	{
		cout << monster->GetName() << "���� " << monster->GetAttack() << "��ŭ ���ظ� �Ծ����ϴ�.\n";
		cout << "���� ü��: " << player->GetHP() << endl;
	}
	else
	{
		cout << "�÷��̾ �����Ͽ����ϴ�.\n";
		return;
	}
}

void BattleManager::PlayerSkill(Player* player, Monster* monster)
{

}




