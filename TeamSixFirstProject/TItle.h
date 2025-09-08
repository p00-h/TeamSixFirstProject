#pragma once
#include <string>
#include <vector>

enum class TitleStyle {
    EDGE = 1
};

void ShowTitle(TitleStyle style = TitleStyle::EDGE);

extern const std::vector<std::string> Gameover;
void PrintGameover();

extern const std::vector<std::string> TheEnd;
void PrintTheEnd();