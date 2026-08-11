#include "controller.hpp"
#include "mainMenu.hpp"
#include "createChar.hpp"
#include "globals.hpp"

Controller::Controller():window(sf::VideoMode({600,600}), "Character Controller", sf::Style::Titlebar | sf::Style::Close), scenes({
        new MainMenu,
        new CreateChar
        })
{
    if(!ImGui::SFML::Init(window))
    {
        throw std::runtime_error("Couldn't init window");
    }
}

Controller::~Controller()
{
    for(Scene* scene: scenes)
    {
        delete scene;
    }
}

void Controller::start()
{
    while(Globals::running && window.isOpen())
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

        ImGuiWindowFlags flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar;

        if(Globals::popupOpen)
        {
            flags |= ImGuiWindowFlags_NoInputs;
        }

        if(ImGui::Begin("##Window", nullptr, flags))
        {
            scenes[(int)Globals::currentScene]->render();
        }
        ImGui::End();

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}
