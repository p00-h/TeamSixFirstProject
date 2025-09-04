#include "Monster.h"
using namespace std;

Monster::Monster(const string& n, int level)
{
	Name = n;
	HP = rand() % (level * 30 - level * 20 + 1) + (level * 20);	//+1�� level =5 ���� 150 - 100 + 1 = 51 rand()% 51�̶�� ���� 0~50 ���� �� + 100�� �������� ���� ��� �������� Ŀ��
	//HP = rand() % (level +20, level + 30);	//������ ������
	Attack = rand() % (level * 10 - level * 5 + 1) + (level * 5);
	//Attack = rand() % (level + 5, level + 10);	//������ ������
}

void Monster::TakeDamage(int dmg)
{
	HP -= dmg;
	if (HP < 0) HP = 0;
}
bool Monster::IsDead()const
{
	return HP <= 0;
}
