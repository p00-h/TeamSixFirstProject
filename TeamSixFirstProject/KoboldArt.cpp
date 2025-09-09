#include "KoboldArt.h"
#include <iostream>

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
	for (const auto& line : KoboldArt)
	{
		std::cout << line << "\n";
	}
}
