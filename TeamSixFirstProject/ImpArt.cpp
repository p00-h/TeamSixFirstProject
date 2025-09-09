#include "ImpArt.h"
#include <iostream>

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
	for (const auto& line : ImpArt)
	{
		std::cout << line << "\n";
	}
}
