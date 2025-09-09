#include "SlimeArt.h"
#include <iostream>

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

void PrintSlimeArt()
{
	for (const auto& line : SlimeArt)
	{
		std::cout << line << "\n";
	}
}