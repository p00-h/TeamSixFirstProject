#pragma once
#include <iostream>
#include <string>
#include "Character.h"	//스킬대미지 주기위해 헤더불러옴


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
	Monster(const std::string& N, int level);	// &문자열 복사하지 않고 직접 참조

	std::string GetName() const	
	{ return Name; }						//HP, Attack을 protected 사용시 cpp로 가야됨.
	int GetHP() const					
	{ return HP; }							//HP, Attack을 protected 사용시 cpp로 가야됨.
	int GetAttack() const				
	{ return Attack; }						//HP, Attack을 protected 사용시 cpp로 가야됨.
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

	void TakeDamage(int dmg);	//주는 대미지 Monster.cpp  줄13 구현
	bool IsDead() const;	// Monster.cpp 줄 18번 구현

	//다형성 가상 함수
	virtual void NormalAttack(Character* target) = 0;
	virtual void UseSkill(Character* target) = 0;

	virtual ~Monster() {}
};
