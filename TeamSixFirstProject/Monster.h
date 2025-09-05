#pragma once
#include <string>

class Monster
{
private:
	std::string Name;
	int HP;
	int Attack;
	int MP;

public:
	Monster(const std::string& N, int level);	// &���ڿ� �������� �ʰ� ���� ����

	std::string GetName() const	
	{ return Name; }						//HP, Attack�� protected ���� cpp�� ���ߵ�.
	int GetHP() const					
	{ return HP; }							//HP, Attack�� protected ���� cpp�� ���ߵ�.
	int GetAttack() const				
	{ return Attack; }						//HP, Attack�� protected ���� cpp�� ���ߵ�.
	int GetMP() const
	{ return MP; }

	void SetHP(int newHP)
	{ HP = newHP; }
	void SetAttack(int newAttack)
	{ Attack = newAttack; };
	void SetMP(int newMP)
	{ MP = newMP; }

	void TakeDamage(int dmg);	//�ִ� ����� Monster.cpp  ��13 ����
	bool IsDead() const;	// Monster.cpp �� 18�� ����
};
