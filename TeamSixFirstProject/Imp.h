#pragma once
#include "Monster.h"

class Imp : public Monster
{
public:
	Imp(int level);

	void Magic();
	void SpiralIce(); //�����̷� ���̽�
	void IceBolt();
	
//private:
//	int MagicBouns;		//������ ���� ����� ���ʽ� ����
	void NormalAttack() override;	//�Ϲ� ����
	void UseSkill() override;	//���� ��ų
};