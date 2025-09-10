#pragma once
#include <string>

enum class TitleStyle {
    EDGE = 1
};

void ShowTitle(TitleStyle style = TitleStyle::EDGE);
