#pragma once
#include "Monster.h"
#include "Character.h"

class Imp : public Monster
{
public:
	Imp(int level);

	void Magic(Character* target);
	void SpiralIce(Character* target); //�����̷� ���̽�
	void IceBolt(Character* target);
	
//private:
//	int MagicBouns;		//������ ���� ����� ���ʽ� ����
	void NormalAttack(Character* target) override;	//�Ϲ� ����
	void UseSkill(Character* target) override;	//���� ��ų
};