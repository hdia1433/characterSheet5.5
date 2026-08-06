#pragma once
#include "scene.hpp"
#include <ftxui/component/component.hpp>

class MainMenu: public Scene
{
private:
    std::vector<std::string> items;
    int selected;
    ftxui::MenuOption menuOption;
    ftxui::Component menu;
    ftxui::Component mainMenu;

public:
    MainMenu();

    ftxui::Element render() override;
    ftxui::Component getComponent() override;
};
