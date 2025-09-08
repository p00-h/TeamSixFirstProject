#pragma once
#include "Monster.h"
#include <string>

class Kobold : public Monster
{
	public:
		Kobold(int level);

		void PickaxeAttack();	//��̰���
		void OreThrow(); //���� ������
		void TramCarRush();
		
//private:
//	int AttackBouns;	//������ ���� ���ʽ� ����

		void NormalAttack() override;	//�Ϲ� ����
		void UseSkill() override;	//���� ��ų
};
