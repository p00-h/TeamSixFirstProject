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
				cout << monster->GetName() << "���� " << character->GetAttack() << "��ŭ ���ظ� �������ϴ�.\n";
				cout << "���� ü��: " << monster->GetHP() << endl;
			}
			else
			{
				cout << "���͸� óġ�Ͽ����ϴ�.\n";
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
			cout << monster->GetName() << "���� " << monster->GetAttack() << "��ŭ ���ظ� �Ծ����ϴ�.\n";
			cout << "���� ü��: " << character->GetHP() << endl;
		}
		else
		{
			cout << "�÷��̾ �����Ͽ����ϴ�.\n";
			
			return;
		}
	}
}
