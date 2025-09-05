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
	Monster(const std::string& N, int level);	// &문자열 복사하지 않고 직접 참조

	std::string GetName() const	
	{ return Name; }						//HP, Attack을 protected 사용시 cpp로 가야됨.
	int GetHP() const					
	{ return HP; }							//HP, Attack을 protected 사용시 cpp로 가야됨.
	int GetAttack() const				
	{ return Attack; }						//HP, Attack을 protected 사용시 cpp로 가야됨.
	int GetMP() const
	{ return MP; }

	void SetHP(int newHP)
	{ HP = newHP; }
	void SetAttack(int newAttack)
	{ Attack = newAttack; };
	void SetMP(int newMP)
	{ MP = newMP; }

	void TakeDamage(int dmg);	//주는 대미지 Monster.cpp  줄13 구현
	bool IsDead() const;	// Monster.cpp 줄 18번 구현
};
