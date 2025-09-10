#pragma once
#include "Monster.h"
#include <string>

class Golem : public Monster
{
	public:
		Golem(int level);

		void Stomp(Character* target);
		void WindMill(Character* target);
		void SharpRock(Character* target);
		
//private:
	//int StompBouns;		//������ ���� ����� ���ʽ� ����
		void NormalAttack(Character* target) override;	//�Ϲ� ����
		void UseSkill(Character* target) override;	//���� ��ų
};
