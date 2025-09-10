#pragma once
#include "Monster.h"
#include <string>

class Dragon : public Monster
{
	public:
		Dragon(int level);

		void FireBrass(Character* target);
		void TailSwing(Character* target);	//���� ����
		void DeadlyCharge(Character* target);	//ġ�����ε���

		void NormalAttack(Character* target) override;	//�Ϲݰ���
		void UseSkill(Character* target) override;	//���� ��ų
};