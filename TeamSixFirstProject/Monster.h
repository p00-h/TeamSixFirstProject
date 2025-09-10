#pragma once
#include <iostream>
#include <string>
#include "Character.h"	//��ų����� �ֱ����� ����ҷ���


class Monster
{
private:
	std::string Name;
	int HP;
	int Attack;
	int MP;
	int AttackBouns;
	//int MaxHP;

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
	int GetAttackBouns()const 
	{ return AttackBouns; }
	//int GetMaxHP()const
	//{ return MaxHP; }

	void SetHP(int newHP)
	{ HP = newHP; }
	void SetAttack(int newAttack)
	{ Attack = newAttack; };
	void SetMP(int newMP)
	{ MP = newMP; }

	void TakeDamage(int dmg);	//�ִ� ����� Monster.cpp  ��13 ����
	bool IsDead() const;	// Monster.cpp �� 18�� ����

	//������ ���� �Լ�
	virtual void NormalAttack(Character* target) = 0;
	virtual void UseSkill(Character* target) = 0;

	virtual ~Monster() {}
};
