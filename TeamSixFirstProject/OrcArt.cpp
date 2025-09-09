#include "OrcArt.h"
#include <iostream>

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
	for(const auto& line : OrcArt)
	{
		std::cout << line << "\n";
	}
}
