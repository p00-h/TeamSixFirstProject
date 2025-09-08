#include "DragonArt.h"
#include <iostream>

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
};

void PrintDragonArt()	//출력 함수 호출
{
	for (const auto& line : DragonArt)
	{ std::cout << line << "\n"; }
}