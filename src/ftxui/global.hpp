#pragma once
#include "sceneName.hpp"
#include <ftxui/component/screen_interactive.hpp>

class Globals
{
public:
    static SceneName* currentScene;
    static ftxui::App* screen;
};
