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

// ==== ASCII 아트 (RPG GAME) ====
static const string BANNER_EDGE = R"(
______ ______  _____   _____   ___  ___  ___ _____ 
| ___ \| ___ \|  __ \ |  __ \ / _ \ |  \/  ||  ___|
| |_/ /| |_/ /| |  \/ | |  \// /_\ \| .  . || |__  
|    / |  __/ | | __  | | __ |  _  || |\/| ||  __| 
| |\ \ | |    | |_\ \ | |_\ \| | | || |  | || |___ 
\_| \_|\_|     \____/  \____/\_| |_/\_|  |_/\____/ 

)";


void ShowTitle(TitleStyle style) {
    ClearScreen_T();
    auto lines = SplitLines(BANNER_EDGE);
    PrintLinesWithDelay(lines, 5);
    cout << "\n";
}
