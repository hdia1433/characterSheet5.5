#include "mainMenu.hpp"
#include "globals.hpp"

MainMenu::MainMenu():warningOpen(false)
{

}

void MainMenu::render()
{
    ImGui::Text("D&D 5.5e Character Manager");
    ImGui::Separator();
    if(ImGui::Button("Create new character"))
    {
        Globals::currentScene = SceneName::CreateChar;
    }
    if(ImGui::Button("Load character"))
    {

    }
    if(ImGui::Button("Quit"))
    {
        Globals::running = false;
    }
}
