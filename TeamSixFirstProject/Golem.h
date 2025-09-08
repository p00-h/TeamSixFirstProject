#pragma once
#include "Monster.h"
#include <string>

class Golem : public Monster
{
	public:
		Golem(int level);

		void Stomp();
		void WindMill();
		void SharpRock();
		
//private:
	//int StompBouns;		//������ ���� ����� ���ʽ� ����
		void NormalAttack() override;	//�Ϲ� ����
		void UseSkill() override;	//���� ��ų
};
