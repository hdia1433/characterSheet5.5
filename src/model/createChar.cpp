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
        "Wizard"
    ),
    currentClass(0),

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

            if(ImGui::Button("Add"))
            {
                chosenClasses.emplace((ClassName)currentClass, 1);
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
            }
        }
        ImGui::End();
    }

}

void CreateChar::classSection()
{
    int totalLevels = 0;

    for(auto& [_, level]: chosenClasses)
    {
        totalLevels += level;
    }

    ImGui::BeginDisabled(totalLevels == 20);

    if(ImGui::Button("Add Class"))
    {
        classPopup = true;
        Globals::popupOpen = true;
    }

    ImGui::EndDisabled();

    for(auto& [className, level]: chosenClasses)
    {
        if(ImGui::CollapsingHeader(classOptions[(int)className], ImGuiTreeNodeFlags_DefaultOpen))
        {
            ImGui::Text("Level");
            ImGui::SameLine();

            ImGui::PushID((int)className);

            if (ImGui::BeginCombo("##Level", std::to_string(level).c_str()))
            {
                for(int i = 1; i <= 20 - totalLevels + level; i++)
                {
                    const bool isSelected = i == level;

                    if(ImGui::Selectable(std::to_string(i).c_str(), isSelected))
                    {
                        level = i;
                    }

                    if(isSelected)
                    {
                        ImGui::SetItemDefaultFocus();
                    }
                }

                ImGui::EndCombo();
            }

            switch(className)
            {
                case ClassName::Barbarian:
                    barbarianSection(level);
                    break;
                default:
                    break;
            }

            if(ImGui::Button("Remove"))
            {
                classToRemove = className;
                removePopup = true;
                Globals::popupOpen = true;
            }

            ImGui::PopID();
        }
    }
}

void CreateChar::barbarianSection(int level)
{
    ImGui::Separator();
    ImGui::Text("Primary Ability: Strength");
    ImGui::Separator();
    ImGui::Text("Hit Die: %dD12", level);
    ImGui::Separator();
    ImGui::Text("Saving Throw Proficiencies: Strength and Constitution");
    ImGui::Separator();
    ImGui::Text("Skill Proficinecies (choose 2):");

    if(ImGui::BeginCombo("##Skill 1", skillToString(barbarianSkills[skill1]).c_str()))
    {
        for(int i = 0; i < IM_ARRAYSIZE(barbarianSkills); i++)
        {
            if(i == skill2)
            {
                continue;
            }

            const bool isSelected = i == skill1;

            if(ImGui::Selectable(skillToString(barbarianSkills[i]).c_str(), isSelected))
            {
                skill1 = i;
            }

            if(isSelected)
            {
                ImGui::SetItemDefaultFocus();
            }
        }

        ImGui::EndCombo();
    }

    if(ImGui::BeginCombo("##Skill 2", skillToString(barbarianSkills[skill2]).c_str()))
    {
        for(int i = 0; i < IM_ARRAYSIZE(barbarianSkills); i++)
        {
            if(i == skill1)
            {
                continue;
            }

            const bool isSelected = i == skill2;

            if(ImGui::Selectable(skillToString(barbarianSkills[i]).c_str(), isSelected))
            {
                skill2 = i;
            }

            if(isSelected)
            {
                ImGui::SetItemDefaultFocus();
            }
        }

        ImGui::EndCombo();
    }

    ImGui::Separator();
    ImGui::Text("Weapon Proficiencies: Simple and Martial");
    ImGui::Separator();
    ImGui::Text("Armour Training: Light, Medium, and Shields");
    ImGui::Separator();
    ImGui::Text("Starting Equipment (choose 1):");

    ImGui::RadioButton("Greataxe, 4 Handaxes, Exporer's Pack, and 15 GP", &classEquipmentSeleciton, 0);
    ImGui::RadioButton("75 GP", &classEquipmentSeleciton, 1);
    ImGui::Separator();
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




