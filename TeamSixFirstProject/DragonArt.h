#pragma once
#include <string>
#include <vector>
//BossMonster, GameManager, BattleManager 에서 공통으로 사용 가능
extern const std::vector<std::string> DragonArt;	//extern : 선언하는 변수 함수가 다른곳에 정의됨을 알리는 키워드.

void PrintDragonArt();	//출력 함수
