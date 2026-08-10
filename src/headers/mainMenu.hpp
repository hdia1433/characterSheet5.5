#pragma once

#include "scene.hpp"

class MainMenu: public Scene
{
private:
    bool warningOpen;

public:
    MainMenu();

    void render() override;
};
