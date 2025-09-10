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

// Title.cpp

const std::vector<std::string> Gameover =
{
R"(   _____                         ____                 )",
R"(  / ____|                       / __ \                )",
R"( | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ )",
R"( | | |_ |/ _` | '_ ` _ \ / _ \ | |  | \ \ / / _ \ '__|)",
R"( | |__| | (_| | | | | | |  __/ | |__| |\ V /  __/ |   )",
R"(  \_____|\__,_|_| |_| |_|\___|  \____/  \_/ \___|_|   )",
R"(                                                      )"
};

void PrintGameover()
{
    for (const auto& line : Gameover)
    {
        std::cout << line << "\n";
    }
}

const std::vector<std::string> TheEnd =
{
R"(  _______ _            ______           _ )",
R"( |__   __| |          |  ____|         | |)",
R"(    | |  | |__   ___  | |____   ___  __| |)",
R"(    | |  | '_ \ / _ \ |  __\ \ / / |/ _` |)",
R"(    | |  | | | |  __/ | |___\ V /| | (_| |)",
R"(    |_|  |_| |_|\___| |______\_/ |_|\__,_|)",
R"(                                          )"
};

void PrintTheEnd()
{
    for (const auto& line : TheEnd)
    {
        std::cout << line << "\n";
    }
}
