#include "Title.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>


#ifdef _WIN32
#include <windows.h>
static void ClearScreen_T() { system("cls"); }
#else
static void ClearScreen_T() { system("clear"); }
#endif

using namespace std;

// 한 줄씩 출력 (애니메이션 효과용)
static void PrintLinesWithDelay(const vector<string>& lines, int ms_per_line = 6) {
    for (const auto& line : lines) {
        cout << line << "\n";
        this_thread::sleep_for(chrono::milliseconds(ms_per_line));
    }
}

static vector<string> SplitLines(const string& block) {
    vector<string> out;
    string cur;
    for (char c : block) {
        if (c == '\n') { out.push_back(cur); cur.clear(); }
        else { cur.push_back(c); }
    }
    if (!cur.empty()) out.push_back(cur);
    return out;
}

// ==== ASCII 아트 ====
static const string BANNER_EDGE = R"(

 _____  _____   ___  ___  ___        _____  _____ __   __
|_   _||  ___| / _ \ |  \/  |       /  ___||_   _|\ \ / /
  | |  | |__  / /_\ \| .  . |       \ `--.   | |   \ V / 
  | |  |  __| |  _  || |\/| |        `--. \  | |   /   \ 
  | |  | |___ | | | || |  | |       /\__/ / _| |_ / /^\ \
  \_/  \____/ \_| |_/\_|  |_/       \____/  \___/ \/   \/
                                                         
                                                Text Game

)";


void ShowTitle(TitleStyle style) {
    ClearScreen_T();
    auto lines = SplitLines(BANNER_EDGE);
    PrintLinesWithDelay(lines, 5);
    cout << "\n";
}

const std::vector<std::string> Gameover =
{
R"( _____   ___  ___  ___ _____   _____  _   _  _____ ______           )"
R"(|  __ \ / _ \ |  \/  ||  ___| |  _  || | | ||  ___|| ___ \          )"
R"(| |  \// /_\ \| .  . || |__   | | | || | | || |__  | |_/ /          )"
R"(| | __ |  _  || |\/| ||  __|  | | | || | | ||  __| |    /           )"
R"(| |_\ \| | | || |  | || |___  \ \_/ /\ \_/ /| |___ | |\ \   _  _  _ )"
R"( \____/\_| |_/\_|  |_/\____/   \___/  \___/ \____/ \_| \_| (_)(_)(_) )"
R"(                                                                     )"
};

void PrintGameover()	//출력 함수 호출
{
    for (const auto& line : Gameover)
    {
        std::cout << line << "\n";
    }
}

const std::vector<std::string> TheEnd =
{
R"( _____  _   _  _____   _____  _   _ ______           )"
R"(|_   _|| | | ||  ___| |  ___|| \ | ||  _  \          )"
R"(  | |  | |_| || |__   | |__  |  \| || | | |          )"
R"(  | |  |  _  ||  __|  |  __| | . ` || | | |          )"
R"(  | |  | | | || |___  | |___ | |\  || |/ /   _  _  _ )"
R"(  \_/  \_| |_/\____/  \____/ \_| \_/|___/   (_)(_)(_) )"
R"(                                                     )"
};

void PrintTheEnd()	//출력 함수 호출
{
    for (const auto& line : TheEnd)
    {
        std::cout << line << "\n";
    }
}