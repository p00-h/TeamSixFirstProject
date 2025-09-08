#pragma once
#include "Monster.h"
#include <string>

class Dragon : public Monster
{
	public:
		Dragon(int level);

		void FireBrass();
		void TailSwing();	//���� ����
		void DeadlyCharge();	//ġ�����ε���

		void NormalAttack() override;	//�Ϲݰ���
		void UseSkill() override;	//���� ��ų
};