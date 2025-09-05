#include <iostream>
#include "GameManager.h"


int main()
{
    srand(time(nullptr));

    GameManager GM;
    GM.Run();

    return 0;
}