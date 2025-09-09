#include <iostream>
#include "GameManager.h"

#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

int main()
{
    srand(time(nullptr));

    PlaySound(TEXT("Field1.wav"), NULL, SND_FILENAME | SND_ASYNC);

    GameManager GM;
    GM.Run();

    return 0;
}