#pragma once
#include "Monster.h"
#include "Character.h"

class Orc : public Monster
{ 
	public:
		Orc(int level);

		void BellyFatAttack(Character* target);	//��� ����
		void ClubAttack(Character* target); //������ ����
		void GroundShaking(Character* target);	//�� �︲

	//private:
	//	int OrcBouns;		//���� ���ʽ� ����� ��� ��
		
		void NormalAttack(Character* target) override;	//�Ϲ� ����
		void UseSkill(Character* target) override;	//���� ��ų
};