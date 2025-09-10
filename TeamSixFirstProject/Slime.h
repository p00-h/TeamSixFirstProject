#pragma once
#include "Monster.h"

class Slime : public Monster
{
	public:
		Slime(int level);

		void StickyBall(Character* target); //������ ��
		void MucusSpit(Character* target); //ħ �b��
		void JumpAttack(Character* target);

	//private:
	//	int SlimeBouns;	//���� ���ʽ� ����� ��� ��
		void NormalAttack(Character* target) override;
		void UseSkill(Character* target) override;
};