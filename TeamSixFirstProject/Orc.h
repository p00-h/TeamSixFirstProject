#pragma once
#include "Monster.h"

class Orc : public Monster
{ 
	public:
		Orc(int level);

		void BellyFatAttack();	//��� ����
		void ClubAttack(); //������ ����
		void GroundShaking();	//�� �︲

	//private:
	//	int OrcBouns;		//���� ���ʽ� ����� ��� ��
};