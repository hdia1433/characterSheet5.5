#include "classCreator.hpp"

ClassCreator::ClassCreator(ClassName className):
    skillProficiencies(Skill::None),
    className(className)
{
    switch(className)
    {
        case ClassName::Barbarian:
            primaryAbilities = Ability::Strength;
            hitDie = 12;
            savingThrowProficiencies = Ability::Strength | Ability::Constitution;
            skillOptions = 
            {
                Skill::AnimalHandling,
                Skill::Athletics,
                Skill::Intimidation,
                Skill::Nature,
                Skill::Perception,
                Skill::Survival
            };
            weaponProficiencies = WeaponType::Simple | WeaponType::Martial;
            armourTraining = ArmourType::Light | ArmourType::Medium | ArmourType::Shields;
            break;
    }
}

void ClassCreator::render(int maxLevel)
{
    if(ImGui::CollapsingHeader(classNameToString(className).c_str(), ImGuiTreeNodeFlags_DefaultOpen))
    {
        ImGui::Text("Level");
        ImGui::SameLine();

        ImGui::PushID((int)className);

        if (ImGui::BeginCombo("##Level", std::to_string(level).c_str()))
        {
            for(int i = 1; i <= maxLevel; i++)
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

        
        ImGui::Separator();
        ImGui::Text("Primary Ability: %s", abilityToString(primaryAbilities).c_str());
        ImGui::Separator();
        ImGui::Text("Hit Die: %dD%d", level, hitDie);
        ImGui::Separator();
        ImGui::Text("Saving Throw Proficiencies: %s", abilityToString(savingThrowProficiencies).c_str());
        ImGui::Separator();
        ImGui::Text("Skill Proficinecies (choose 2):");

        if(ImGui::BeginCombo("##Skill 1", skillToString(skillSelection1).c_str()))
        {
            for(int i = 0; i < skillOptions.size(); i++)
            {
                if(skillOptions[i] == skillSelection2)
                {
                    continue;
                }

                const bool isSelected = skillOptions[i] == skillSelection1;

                if(ImGui::Selectable(skillToString(skillOptions[i]).c_str(), isSelected))
                {
                    skillSelection1 = skillOptions[i];
                }

                if(isSelected)
                {
                    ImGui::SetItemDefaultFocus();
                }
            }

            ImGui::EndCombo();
        }

         if(ImGui::BeginCombo("##Skill 2", skillToString(skillSelection2).c_str()))
         {
             for(int i = 0; i < skillOptions.size(); i++)
             {
                 if(skillOptions[i] == skillSelection2)
                 {
                     continue;
                 }

                 const bool isSelected = skillOptions[i] == skillSelection2;

                 if(ImGui::Selectable(skillToString(skillOptions[i]).c_str(), isSelected))
                 {
                     skillSelection2 = skillOptions[i];
                 }

                 if(isSelected)
                 {
                     ImGui::SetItemDefaultFocus();
                 }
             }

             ImGui::EndCombo();
         }

         ImGui::Separator();
         ImGui::Text("Weapon Proficiencies: %s", weaponTypeToString(weaponProficiencies).c_str());
         ImGui::Separator();
         ImGui::Text("Armour Training: Light, Medium, and Shields");
         ImGui::PopID();
    }
}
