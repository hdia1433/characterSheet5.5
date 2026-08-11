#pragma once

enum class Background
{
    Acolyte
};

inline std::string backgroundToString(Background background)
{
    return std::array
    {
        "Acolyte"
    }[(int)background];
}
