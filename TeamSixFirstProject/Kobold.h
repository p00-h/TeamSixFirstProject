#pragma once
#include "Monster.h"
#include "Character.h"
#include <string>

class Kobold : public Monster
{
	public:
		Kobold(int level);

		void PickaxeAttack(Character* target);	//��̰���
		void OreThrow(Character* target); //���� ������
		void TramCarRush(Character* target);
		
//private:
//	int AttackBouns;	//������ ���� ���ʽ� ����

		void NormalAttack(Character* target) override;	//�Ϲ� ����
		void UseSkill(Character* target) override;	//���� ��ų
};
