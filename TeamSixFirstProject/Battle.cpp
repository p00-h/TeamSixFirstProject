#include "Battle.h"


using namespace std;


Battle::Battle()
{

}

void Battle::CharaterAttack(Character* character, Monster* monster)
{
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
}

void Battle::MonsterAttack(Character* character, Monster* monster)
{
	character->SetHp(character->GetHp() - monster->GetAttack());
	if (character->GetHp() > 0)
	{
		cout << monster->GetName() << "���� " << monster->GetAttack() << "��ŭ ���ظ� �Ծ����ϴ�.\n";
		cout << "���� ü��: " << character->GetHp() << endl;
	}
	else
	{
		cout << "�÷��̾ �����Ͽ����ϴ�.\n";

		return;
	}
}

int Battle::StartBattle(Character* character, Monster* monster)
{
	DirectionManager Direction;
	vector<string> items{ "����","��ų ���", "����" };
	int count = items.size();
	int sel = 0;
	int go = 0;
	while (true)
	{
		//Ư�� ��ġ�� �ؽ�Ʈ ������Ű�� ��� Ʃ�ʹ� & ������� �����ϱ�
		cout << "> " << items[0] << " \n";
		cout << "  " << items[1] << " \n";
		cout << "  " << items[2] << "\n";

		//����Ű�� �Է¹޾Ƽ� ���û����� ����.
		sel = Direction.Direction();
		if (sel != 122) go += sel;

		if (go >= items.size()) go = 0;
		else if (go < 0) go = items.size() - 1;

		if (go >= 0 && go < items.size())
		{
			for (int i = 0; i < count; i++)
			{
				if (i == go)
				{
					cout << "> " << items[i] << " \n";
				}
				else cout << "  " << items[i] << "\n";
			}
		}
		//���ǵ� ������ ���ǵ尡 ���ͺ��� ���ٸ� ���ʿ��� �Լ��� ����ǵ���;
		//MonsterAttack(character, monster);
		//if (character->GetHP() == 0 || monster->GetHP() == 0) break;
		if (sel == 122)
		{
			switch (go)
			{
			case 0:
				CharaterAttack(character, monster);
				break;
			case 1:
				//��ų ������
				cout << "�̱��� �ܰ��Դϴ�.";
				break;
			//case 2:
			//	cout << "���������� �����ƽ��ϴ�.\n";
			//	return;
			default:
				break;
			}
			if (monster->GetHP() <= 0) return 1;
		}

		MonsterAttack(character, monster);
		if (character->GetHp() <= 0) return 0;
		//���� ���Ÿ� ��� �Ұ�����?
		//�����Ѱ�? �ƴϸ� ��Ʋ�� ��������?
	}
}

