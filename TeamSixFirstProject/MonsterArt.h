#pragma once
#include <string>
#include <vector>
#include <iostream>

// === ��Ʈ ������ extern ���� ===
// ����: ���� ASCII ��Ʈ �����ʹ� �ٸ� ���� ����(.cpp)�� ���ǵǾ� �־�� �մϴ�.
extern const std::vector<std::string> DragonArt; // �巡��
extern const std::vector<std::string> GolemArt; // ��
extern const std::vector<std::string> ImpArt; // ����
extern const std::vector<std::string> KoboldArt; // �ں�Ʈ
extern const std::vector<std::string> OrcArt; // ��ũ
extern const std::vector<std::string> SlimeArt; // ������

// === ���� ��� �Լ� ���� ===
// ���� ������Ʈ���� ��� ���� ��� �Լ� �ñ״�ó�� �״�� �����մϴ�.
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