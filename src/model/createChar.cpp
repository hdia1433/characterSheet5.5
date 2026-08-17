#include "createChar.hpp"
#include "globals.hpp"

CreateChar::CreateChar():
    classPopup(false),
    removePopup(false),
    classOptions(
        "Barbarian",
        "Bard",
        "Cleric",
        "Druid",
        "Fighter",
        "Monk",
        "Paladin",
        "Ranger",
        "Rogue",
        "Sorcerer",
        "Warlock",
        "Wizard",
        "None"
    ),
    currentClass(IM_ARRAYSIZE(classOptions) - 1),

    skill1(0),
    skill2(1),

    barbarianSkills
    {
        Skill::AnimalHandling,
        Skill::Athletics,
        Skill::Intimidation,
        Skill::Nature,
        Skill::Perception,
        Skill::Survival
    },

    classEquipmentSeleciton(0),

    background(Background::Acolyte),
    backgroundOptions
    (
        "Acolyte"
    ),
    backgroundSkillType(0)
{

}

void CreateChar::render()
{
    ImGui::BeginDisabled(classPopup);
    ImGui::Text("Creating new Character");
    if(ImGui::Button("Save"))
    {
        
    }
    if(ImGui::BeginTabBar("##Creation Steps"))
    {
        if(ImGui::BeginTabItem("Class"))
        {
            classSection();
            ImGui::EndTabItem();
        }
        if(ImGui::BeginTabItem("Origin"))
        {
            originSelection();
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
    ImGui::EndDisabled();

    if(classPopup)
    {
        if(ImGui::Begin("Choose a class", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize))
        {
            if(ImGui::BeginCombo("##Class Dropdown", classOptions[currentClass]))
            {
                for(int i = 0; i < IM_ARRAYSIZE(classOptions); i++)
                {
                    if(chosenClasses.contains((ClassName)i))
                    {
                        continue;
                    }

                    const bool isSelected = i == currentClass;

                    if(ImGui::Selectable(classOptions[i], isSelected))
                    {
                        currentClass = i;
                    }

                    if(isSelected)
                    {
                        ImGui::SetItemDefaultFocus();
                    }
                }

                ImGui::EndCombo();
            }

            ImGui::BeginDisabled(currentClass == IM_ARRAYSIZE(classOptions) - 1);
            if(ImGui::Button("Add"))
            {
                chosenClasses.emplace((ClassName)currentClass, (ClassName)currentClass);
                currentClass = IM_ARRAYSIZE(classOptions) - 1;
                classPopup = false;
                Globals::popupOpen = false;
            }
            ImGui::EndDisabled();

            ImGui::SameLine();
            if(ImGui::Button("Cancel"))
            {
                classPopup = false;
                Globals::popupOpen = false;
            }
        }
        ImGui::End();
    }
    else if(removePopup)
    {
        if(ImGui::Begin("##remove", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize))
        {
            ImGui::Text("This action cannot be undone. Do you want to continue?");
            if(ImGui::Button("Continue"))
            {
                removePopup = false;
                Globals::popupOpen = false;
                chosenClasses.erase(classToRemove);
            }
            ImGui::SameLine();
            if(ImGui::Button("Cancel"))
            {
                removePopup = false;
                Globals::popupOpen = false;
                chosenClasses.at(classToRemove).cancelRemoval();
            }
        }
        ImGui::End();
    }

}

void CreateChar::classSection()
{
    int totalLevels = 0;

    for(auto& [_, classCreator]: chosenClasses)
    {
        totalLevels += classCreator.getLevel();
    }

    ImGui::BeginDisabled(totalLevels == 20);
    if(ImGui::Button("Add Class"))
    {
        classPopup = true;
        Globals::popupOpen = true;
    }
    ImGui::EndDisabled();

    for(auto& [className, classCreator]: chosenClasses)
    {
        classCreator.render(20 - totalLevels + classCreator.getLevel());

        if(classCreator.getWantsRemoval())
        {
            classToRemove = className;
            removePopup = true;
            Globals::popupOpen = true;
        }
    }
}

void CreateChar::originSelection()
{
    ImGui::Text("Background:");
    if(ImGui::BeginCombo("##Background", backgroundOptions[(int)background]))
    {
        for(int i = 0; i < IM_ARRAYSIZE(backgroundOptions); i++)
        {
            const bool isSelected = i == (int)background;

            if(ImGui::Selectable(backgroundOptions[i], isSelected))
            {
                background = (Background)i;
            }

            if(isSelected)
            {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }
    ImGui::Separator();
}




