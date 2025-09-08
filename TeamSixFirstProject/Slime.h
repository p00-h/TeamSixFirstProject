#pragma once
#include "Monster.h"

class Slime : public Monster
{
	public:
		Slime(int level);

		void StickyBall(); //������ ��
		void MucusSpit(); //ħ �b��
		void JumpAttack();

	//private:
	//	int SlimeBouns;	//���� ���ʽ� ����� ��� ��
		void NormalAttack() override;
		void UseSkill() override;
};