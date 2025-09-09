#pragma once
#include <string>
#include <vector>
#include <iostream>

// === 아트 데이터 extern 선언 ===
// 주의: 실제 ASCII 아트 데이터는 다른 번역 단위(.cpp)에 정의되어 있어야 합니다.
extern const std::vector<std::string> DragonArt; // 드래곤
extern const std::vector<std::string> GolemArt; // 골렘
extern const std::vector<std::string> ImpArt; // 임프
extern const std::vector<std::string> KoboldArt; // 코볼트
extern const std::vector<std::string> OrcArt; // 오크
extern const std::vector<std::string> SlimeArt; // 슬라임

// === 개별 출력 함수 선언 ===
// 기존 프로젝트에서 사용 중인 출력 함수 시그니처를 그대로 유지합니다.
void PrintDragonArt();
void PrintGolemArt();
void PrintImpArt();
void PrintKoboldArt();
void PrintOrcArt();
void PrintSlimeArt(); 

enum class MonsterArtId {
	Dragon,
	Golem,
	Imp,
	Kobold,
	Orc,
	Slime
};

inline void PrintArt(const std::vector<std::string>& art) {
	for (const auto& line : art) std::cout << line << '\n';
}

inline void PrintMonsterArt(MonsterArtId id) {
	switch (id) {
	case MonsterArtId::Dragon: return PrintDragonArt();
	case MonsterArtId::Golem: return PrintGolemArt();
	case MonsterArtId::Imp: return PrintImpArt();
	case MonsterArtId::Kobold: return PrintKoboldArt();
	case MonsterArtId::Orc: return PrintOrcArt();
	}
}