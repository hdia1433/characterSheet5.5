#include "mainMenu.hpp"

MainMenu::MainMenu()
{

}

void MainMenu::render()
{
    ImGui::Text("D&D 5.5e Character Manager");
    ImGui::Separator();
    ImGui::Button("Wipe data and create new character");
    ImGui::Button("Quit");
}
