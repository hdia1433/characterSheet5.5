#include "controller.hpp"
#include "mainMenu.hpp"
#include "globals.hpp"

Controller::Controller():window(sf::VideoMode({600,600}), "Character Controller", sf::Style::Titlebar | sf::Style::Close), scenes({new MainMenu})
{
    if(!ImGui::SFML::Init(window))
    {
        throw std::runtime_error("Couldn't init window");
    }
}

void Controller::start()
{
    while(window.isOpen())
    {
        while(const std::optional event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, *event);
            if(event->is<sf::Event::Closed>())
            {
                window.close();
                break;
            }
        }

        if(!window.isOpen())
        {
            break;
        }

        sf::Time dt = deltaClock.reset();

        if(dt <= sf::Time::Zero)
        {
            dt = sf::seconds(1.f/60);
        }

        ImGui::SFML::Update(window, dt);

        window.clear();

        ImGui::SetNextWindowPos(ImVec2(0.f, 0.f), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2(600.f, 600.f), ImGuiCond_Always);

        if(ImGui::Begin("##Window", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar))
        {
            scenes[(int)Globals::currentScene]->render();
        }
        ImGui::End();

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}
