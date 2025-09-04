#include <iostream>
#include "GameManager.h"


int main()
{
    srand(time(nullptr));

    GameManager GM;
    GM.Run();

    std::cout << "* 닉네임을 입력해주세요: ";
    std::string name;
    std::cin >> name;

    std::cout << name << "\n";

    system("pause");
    return 0;
}