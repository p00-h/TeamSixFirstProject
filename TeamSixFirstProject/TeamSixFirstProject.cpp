#include <iostream>
#include "GameManager.h"


int main()
{
    srand(time(nullptr));

    std::cout << "* 닉네임을 입력해주세요: ";
    std::string name;
    std::cin >> name;

    std::cout << name << "\n";

    GameManager GM;
    GM.Battle(name);

    system("pause");
    return 0;
}