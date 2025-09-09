#include <iostream>
#include "GameManager.h"
#include <Windows.h>
#include <mmsystem.h>
#include <Digitalv.h>

int main()
{
    srand(time(nullptr));

    MCI_OPEN_PARMS mciOpen = { 0 };
    mciOpen.lpstrElementName = L"Field1.mp3";
    if (mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD_PTR)&mciOpen) != 0) {
        MessageBox(NULL, L"파일 열기 실패", L"에러", MB_OK);
    }
    UINT dwID = mciOpen.wDeviceID;
    MCI_PLAY_PARMS mciPlay = { 0 };
    mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR)&mciPlay);

    GameManager GM;
    GM.Run();

    return 0;
}