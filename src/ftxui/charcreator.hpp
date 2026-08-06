#pragma once
#include "scene.hpp"

#include <ftxui/component/component.hpp>

class CharCreator: public Scene
{
private:
    ftxui::Component charCreatorScene;

    ftxui::Component tabs;
    ftxui::MenuOption tabOptions;

    ftxui::Component classTab;

public:
    CharCreator();


    ftxui::Component getComponent() override;

    ftxui::Element render() override;
};
