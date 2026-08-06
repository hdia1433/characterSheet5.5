#include "mainMenu.hpp"
#include "global.hpp"

MainMenu::MainMenu():items(
        {
            "New Character (Will replace the current character)",
            "Quit"
        }), 
        selected(0)
{
    menuOption = ftxui::MenuOption();

    menuOption.on_enter = [this]
    {
        switch (selected) 
        {
            case 0:
                break;
            case 1:
                Globals::screen->Exit();
                break;
        }
    };

    menu = ftxui::Menu(&items, &selected, menuOption);

    mainMenu = ftxui::Container::Vertical(
                {
                    menu
                });
}

ftxui::Element MainMenu::render()
{
    return ftxui::vbox({
        ftxui::text("D&D 5.5e Character Sheet Manager") | ftxui::bold | ftxui::center,
        ftxui::separator(),
        mainMenu->Render()
    });
}

ftxui::Component MainMenu::getComponent()
{
    return mainMenu;
}
