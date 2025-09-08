#include "GolemArt.h"
#include <iostream>

const std::vector<std::string> GolemArt =
{
    R"(		   _______MM&			)",
    R"(	          /A  <||>   #¡¬   			)",
    R"(	   ___    ¡¬;;m___;;##/   ___		)",
    R"(	/    #|	   /       #¡¬   |   #¡¬    		)",
    R"(	|    #|	   ¡¬m_mm;;;/    |    #|         	)",
    R"(        /   ;;;¡¬ | ;;|  | ;;|   /   ;;;¡¬	    	)",
    R"(       |___;;;##|/__;;;¡¬/__;;;¡¬|___;;;##|		)",
};

void PrintGolemArt()
{
    for (const auto& line : GolemArt)
    {
        std::cout << line << "\n";
    }
}