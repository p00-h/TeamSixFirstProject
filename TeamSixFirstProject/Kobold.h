#pragma once
#include "Monster.h"
<<<<<<< HEAD
=======
#include "Character.h"
>>>>>>> parent of 5e63b35 (Merge branch 'main' into dev)
#include <string>

class Kobold : public Monster
{
	public:
		Kobold(int level);

<<<<<<< HEAD
		//void BaseAttack();		//�ں�Ʈ �Ϲ� ���� ����, Kobold.cpp �� 17����
		
//private:
//	int AttackBouns;	//������ ���� ���ʽ� ����
=======
		void PickaxeAttack(Character* target);	//��̰���
		void OreThrow(Character* target); //���� ������
		void TramCarRush(Character* target);
		
//private:
//	int AttackBouns;	//������ ���� ���ʽ� ����

		void NormalAttack(Character* target) override;	//�Ϲ� ����
		void UseSkill(Character* target) override;	//���� ��ų
>>>>>>> parent of 5e63b35 (Merge branch 'main' into dev)
};
