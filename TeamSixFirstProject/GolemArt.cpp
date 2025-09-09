#include "GolemArt.h"
#include <iostream>

const std::vector<std::string> GolemArt =
{
    R"(                                                )",
    R"(		   _______MM&			)",
    R"(	          /A  <||>   #¡¬   			)",
    R"(	   ___    ¡¬;;m___;;##/   ___		)",
    R"(	/    #|	   /       #¡¬   |   #¡¬    		)",
    R"(	|    #|	   ¡¬m_mm;;;/    |    #|         	)",
    R"(        /   ;;;¡¬ | ;;| | ;;|   /   ;;;¡¬	    	)",
    R"(       |___;;;##| |_;;| |_;;|  |___;;;##|		)",
    R"(                                                               )",
};

void PrintGolemArt()
{
    for (const auto& line : GolemArt)
    {
        std::cout << line << "\n";
    }
}