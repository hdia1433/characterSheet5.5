#pragma once
#include <ftxui/component/component.hpp>

class Scene
{
public:
    virtual ~Scene();

    virtual ftxui::Element render() = 0;
    virtual ftxui::Component getComponent() = 0;
};
