#include "MonsterArt.h"
#include <cctype>

// 통합 구현 파일: 기존 DragonArt.cpp, GolemArt.cpp, ImpArt.cpp, KoboldArt.cpp, OrcArt.cpp (+ Slime) 내용을 한 곳에 모았습니다.
// 주의: Slime 아트와 PrintSlimeArt()는 현재 MonsterArt.h에 선언되어 있지 않습니다.
// 사용 중이라면 MonsterArt.h에 선언 추가를 권장합니다. (원하면 바로 업데이트해드릴게요)

// ===================== Dragon =====================
const std::vector<std::string> DragonArt =
{
    R"(                   +      +                                                                       )",
    R"(       /|        /|      /|            |＼                                                            )",
    R"(     </  |      /  |    /  |           ＼ ＼>                                                    )",
    R"(  </     |     /           ＼            ＼  ＼>                                               )",
    R"(  <|       |  |  |＼  ∠|   ; ＼ /         ＼＼ ＼>                                          )",
    R"(<|            ＼ /'''''''＼;＼  ＼/        |   ＼  ＼>                                )",
    R"(  |   ＼        ＼* *   /; ==＼   ＼/    /      | ＼ ＼>                            )",
    R"(/      |           vAAv  ; ＼=＼    ＼/        |    ＼  ＼>                    )",
    R"(      /           ____       |==＼       ____ /    |  |   ＼>                   )",
    R"(   |            /       ＼_ /=====＼   /      ＼      /     |                  )",
    R"(              /       /    /=======＼ /     _ //    /       |                     )",
    R"(             ( (  (       /=========( (  (   |     /         |                   )",
    R"(                          |==========＼    ＼    ＼       |               )",
    R"(                           ＼===========＼    ＼    ＼     |                )",
    R"()",
};

void PrintDragonArt()
{
    PrintArt(DragonArt);
}

// ===================== Golem =====================
const std::vector<std::string> GolemArt =
{
    R"(                                                )",
    R"(\t\t   _______MM&\t\t	)",
    R"(\t          /A  <||>   #¡¬   \t\t\t)",
    R"(\t   ___    ¡¬;;m___;;##/   ___\t\t)",
    R"(\t/    #|\t   /       #¡¬   |   #¡¬   \t\t)",
    R"(\t|    #|\t   ¡¬m_mm;;;/    |    #|         \t)",
    R"(        /   ;;;¡¬ | ;;| | ;;|   /   ;;;¡¬\t    \t)",
    R"(       |___;;;##| |_;;| |_;;|  |___;;;##|\t\t)",
    R"(                                                               )",
};

void PrintGolemArt()
{
    PrintArt(GolemArt);
}

// ===================== Imp =====================
const std::vector<std::string> ImpArt =
{
    R"(                                                          )",
    R"(                   /¡¬                                  )",
    R"(                  /__ ¡¬                                     )",
    R"(                 / o  o ¡¬                          )",
    R"(                 ¡¬  A  /      *                   )",
    R"(                  /¡¬_ /;¡¬   /                            )",
    R"(               @ | ____;;| ¡¬/                           )",
    R"(                  ¡¬  _ #/   @                            )",
    R"(                   |_||_|                             )",
};

void PrintImpArt()
{
    PrintArt(ImpArt);
}

// ===================== Kobold =====================
const std::vector<std::string> KoboldArt =
{
    R"(                                                         )",
    R"(                  _________                   )",
    R"(                 /..     ;;¡¬_                 )",
    R"(                <|¨¬ /  ¨¬ ;;_>                       )",
    R"(                 |  /__ <;/  ====                     )",
    R"(                 /¡¬_|___/ = //  =                   )",
    R"(              / /__________@//                )",
    R"(             @  |_|_|_|_|_|_|                    )",
    R"(                 | ;|  | ;|                      )",
};

void PrintKoboldArt()
{
    PrintArt(KoboldArt);
}

// ===================== Orc =====================
const std::vector<std::string> OrcArt =
{
    R"(            /¡¬___/¡¬                    )",
    R"(           ( ¢ª   ¢ª  )                     )",
    R"(           /(¤·¤·  )   ¡¬                     )",
    R"(          //         ;¡¬ ¡¬               )",
    R"(        / (           ;;)  ¡¬           )",
    R"(       |__| ++__@@@##==|-___|              )",
    R"(          (    ______    )                         )",
    R"(          |__;|      |__;|                                     )",
    R"(                                                      )",
};

void PrintOrcArt()
{
    PrintArt(OrcArt);
}

// ===================== Slime (선택) =====================
// 현재 헤더에는 선언이 없지만, 정의까지 한 번에 관리하고 싶다면 함께 둡니다.
const std::vector<std::string> SlimeArt =
{
    R"(                                                         )",
    R"(                                                         )",
    R"(                 __________                                     )",
    R"(                /         ;¡¬                  )",
    R"(               / ¤·¤µ ¤·  ;#|                )",
    R"(              (__________;##/                                         )",
    R"(                                                         )",
    R"(                                                         )",
    R"(                                                         )",
};

// 선언이 필요하면 MonsterArt.h에 다음을 추가하세요:
//   extern const std::vector<std::string> SlimeArt;
//   void PrintSlimeArt();
void PrintSlimeArt()
{
    PrintArt(SlimeArt);
}
