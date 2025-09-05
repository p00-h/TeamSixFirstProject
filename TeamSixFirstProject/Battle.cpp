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
}

void Battle::MonsterAttack(Character* character, Monster* monster)
{
	character->SetHp(character->GetHp() - monster->GetAttack());
	if (character->GetHp() > 0)
	{
		cout << monster->GetName() << "에게 " << monster->GetAttack() << "만큼 피해를 입었습니다.\n";
		cout << "남은 체력: " << character->GetHp() << endl;
	}
	else
	{
		cout << "플레이어가 기절하였습니다.\n";

		return;
	}
}

int Battle::StartBattle(Character* character, Monster* monster)
{
	DirectionManager Direction;
	vector<string> items{ "공격","스킬 사용", "도주" };
	int count = items.size();
	int sel = 0;
	int go = 0;
	while (true)
	{
		//특정 위치에 텍스트 고정시키는 방법 튜터님 & 팀원들과 상의하기
		cout << "> " << items[0] << " \n";
		cout << "  " << items[1] << " \n";
		cout << "  " << items[2] << "\n";

		//방향키로 입력받아서 선택사항을 선택.
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
		//스피드 구현시 스피드가 몬스터보다 낮다면 이쪽에서 함수가 실행되도록;
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
				//스킬 구현시
				cout << "미구현 단계입니다.";
				break;
			//case 2:
			//	cout << "성공적으로 도망쳤습니다.\n";
			//	return;
			default:
				break;
			}
			if (monster->GetHP() <= 0) return 1;
		}

		MonsterAttack(character, monster);
		if (character->GetHp() <= 0) return 0;
		//몬스터 제거를 어디서 할것인지?
		//생성한곳? 아니면 배틀이 끝나는쪽?
	}
}

