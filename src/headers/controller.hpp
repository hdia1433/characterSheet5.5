#pragma once

#include "scene.hpp"

#include <SFML/Graphics.hpp>

class Controller
{
private:
    sf::RenderWindow window;
    sf::Clock deltaClock;

    std::vector<Scene*> scenes;

public:
    Controller();

    void start();
};
