#include "classCreator.hpp"
#include "weapon.hpp"
#include "equipmentPack.hpp"
#include "armour.hpp"
#include "ammunition.hpp"

ClassCreator::ClassCreator(const ClassName& className):
    level(1),
    skillProficiencies(Skill::None),
    className(className),
    equipmentSelection(0),
    toolSelection(0)
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
            weaponProficiencies = WeaponType::SimpleMelee | WeaponType::MartialMelee | WeaponType::SimpleRanged | WeaponType::MartialRanged;
            armourTraining = ArmourType::Light | ArmourType::Medium | ArmourType::Shields;

            equipmentOption1 = 
            {
                greataxe(1),
                handaxe(4),
                explorersPack(1)
            };
            moneyOption1 = Money{.amount = 15, .coinType = CoinType::Gold};
            moneyOption2 = Money{.amount = 75, .coinType = CoinType::Gold};
            break;
        case ClassName::Bard:
            primaryAbilities = Ability::Charisma;
            hitDie = 6;
            savingThrowProficiencies = Ability::Dexterity | Ability::Charisma;
            skillOptions = 
            {
                Skill::Acrobatics,
                Skill::AnimalHandling,
                Skill::Arcana,
                Skill::Athletics,
                Skill::Deception,
                Skill::History,
                Skill::Insight,
                Skill::Intimidation,
                Skill::Investigation,
                Skill::Medicine,
                Skill::Nature,
                Skill::Perception,
                Skill::Performance,
                Skill::Persuasion,
                Skill::Religion,
                Skill::SleightOfHand,
                Skill::Stealth,
                Skill::Survival
            };
            weaponProficiencies = WeaponType::SimpleMelee | WeaponType::SimpleRanged;
            toolProficiencyOptions =
            {
                ToolType::Bagpipes,
                ToolType::Drum,
                ToolType::Dulcimer,
                ToolType::Flute,
                ToolType::Horn,
                ToolType::Lute,
                ToolType::Lyre,
                ToolType::PanFlute,
                ToolType::Shawm,
                ToolType::Viol
            };
            armourTraining = ArmourType::Light;
            equipmentOption1 = 
            {
                leather(),
                dagger(2),
                entertainersPack()
            };
            additionEquipmentOptions = "Any musical instrument";

            toolOptions =
            {
                bagpipes(),
                drum(),
                dulcimer(),
                flute(),
                horn(),
                lute(),
                lyre(),
                panFlute(),
                shawm(),
                viol()
            };

            moneyOption1 = Money{19, CoinType::Gold};
            moneyOption2 = Money{90, CoinType::Gold};
            break;
        case ClassName::Cleric:
            primaryAbilities = Ability::Wisdom;
            hitDie = 8;
            savingThrowProficiencies = Ability::Wisdom | Ability::Charisma;
            skillOptions = 
            {
                Skill::History,
                Skill::Insight,
                Skill::Medicine,
                Skill::Persuasion,
                Skill::Religion
            };
            weaponProficiencies = WeaponType::SimpleMelee | WeaponType::SimpleRanged;
            armourTraining = ArmourType::Light | ArmourType::Medium | ArmourType::Shields;
            equipmentOption1 = 
            {
                chainShirt(),
                shield(),
                mace(),
                priestsPack()
            };
            additionEquipmentOptions = "Any holy symbol";

            gearOptions = 
            {
                amulet(),
                emblem(),
                reliquary()
            };

            moneyOption1 = {7, CoinType::Gold};
            moneyOption2 = {110, CoinType::Gold};
            break;
        case ClassName::Druid:
            primaryAbilities = Ability::Wisdom;
            hitDie = 8;
            savingThrowProficiencies = Ability::Intelligence | Ability::Wisdom;
            skillOptions =
            {
                Skill::AnimalHandling,
                Skill::Arcana,
                Skill::Insight,
                Skill::Medicine,
                Skill::Nature,
                Skill::Perception,
                Skill::Religion,
                Skill::Survival
            };
            weaponProficiencies = WeaponType::SimpleMelee | WeaponType::SimpleRanged;
            toolProficiencies = ToolType::HerbalismKit;
            armourTraining = ArmourType::Light | ArmourType::Shields;
            equipmentOption1 =
            {
                leather(),
                shield(),
                sickle(),
                quarterstaff(),
                explorersPack(),
                herbalismKit()
            };
            moneyOption1 = {9, CoinType::Gold};
            moneyOption2 = {50, CoinType::Gold};
            break;
        case ClassName::Fighter:
            abilityOptions =
            {
                Ability::Strength,
                Ability::Dexterity
            };
            hitDie = 10;
            savingThrowProficiencies = Ability::Strength | Ability::Constitution;
            skillOptions =
            {
                Skill::Acrobatics,
                Skill::AnimalHandling,
                Skill::Athletics,
                Skill::History,
                Skill::Insight,
                Skill::Intimidation,
                Skill::Persuasion,
                Skill::Perception,
                Skill::Survival
            };
            weaponProficiencies = WeaponType::Simple | WeaponType::Martial;
            armourTraining = ArmourType::Light | ArmourType::Medium | ArmourType::Heavy | ArmourType::Shields;
            equipmentOption1 =
            {
                chainMail(),
                greatsword(),
                flail(),
                javelin(8),
                dungeoneersPack()
            };
            equipmentOption2 =
            {
                studdedLeather(),
                scimitar(),
                shortsword(),
                longbow(),
                arrow(20),
                quiver(),
                dungeoneersPack()
            };
            moneyOption1 = {4, CoinType::Gold};
            moneyOption2 = {11, CoinType::Gold};
            moneyOption3 = {155, CoinType::Gold};
            break;
    }
}

ClassCreator::~ClassCreator()
{
    for(Equipment* equipment: classEquipment)
    {
        delete equipment;
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
        if(!abilityOptions.empty())
        {
            ImGui::Text("Primary Ability:");

            if(ImGui::BeginCombo("##ability", abilityToString(primaryAbilities).c_str()))
            {
                for(int i = 0; i < abilityOptions.size(); i++)
                {
                    const bool isSelected = abilityOptions[i] == primaryAbilities;

                    if(ImGui::Selectable(abilityToString(abilityOptions[i]).c_str(), isSelected))
                    {
                        primaryAbilities = abilityOptions[i];
                    }

                    if(isSelected)
                    {
                        ImGui::SetItemDefaultFocus();
                    }
                }
                ImGui::EndCombo();
            }
        }
        else
        {
            ImGui::TextWrapped("Primary Ability: %s", abilityToString(primaryAbilities).c_str());
        }
        ImGui::Separator();
        ImGui::Text("Hit Die: %dD%d", level, hitDie);
        ImGui::Separator();
        ImGui::TextWrapped("Saving Throw Proficiencies: %s", abilityToString(savingThrowProficiencies).c_str());
        ImGui::Separator();
        int skillNum = className == ClassName::Bard ? 3 : 2;
        ImGui::Text("Skill Proficinecies (choose %d):", skillNum);

        if(ImGui::BeginCombo("##Skill 1", skillToString(skillSelection1).c_str()))
        {
            for(int i = 0; i < skillOptions.size(); i++)
            {
                if((skillOptions[i] == skillSelection2) | (skillNum > 2 && skillOptions[i] == skillSelection3))
                {
                    continue;
                }

                const bool isSelected = skillOptions[i] == skillSelection1;

                if(ImGui::Selectable(skillToString(skillOptions[i]).c_str(), isSelected))
                {
                    skillSelection1 = skillOptions[i];
                    skillProficiencies = skillSelection1 | skillSelection2;
                    if(skillNum > 2)
                    {
                        skillProficiencies |= skillSelection3;
                    }
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
                 if((skillOptions[i] == skillSelection1) | (skillNum > 2 && skillOptions[i] == skillSelection3))
                 {
                     continue;
                 }

                 const bool isSelected = skillOptions[i] == skillSelection2;

                 if(ImGui::Selectable(skillToString(skillOptions[i]).c_str(), isSelected))
                 {
                    skillSelection2 = skillOptions[i];
                    skillProficiencies = skillSelection1 | skillSelection2;
                    if(skillNum > 2)
                    {
                        skillProficiencies |= skillSelection3;
                    }
                 }

                 if(isSelected)
                 {
                     ImGui::SetItemDefaultFocus();
                 }
             }

             ImGui::EndCombo();
         }

        if(skillNum > 2 && ImGui::BeginCombo("##Skill 3", skillToString(skillSelection3).c_str()))
        {
            for(int i = 0; i < skillOptions.size(); i++)
            {
                if(skillOptions[i] == skillSelection1 | skillOptions[i] == skillSelection2)
                {
                    continue;
                }

                const bool isSelected = skillOptions[i] == skillSelection2;

                if(ImGui::Selectable(skillToString(skillOptions[i]).c_str()), isSelected)
                {
                    skillSelection3 = skillOptions[i];
                    skillProficiencies = skillSelection1 | skillSelection2 | skillSelection3;
                }
            }
        }

         ImGui::Separator();
         ImGui::TextWrapped("Weapon Proficiencies: %s", weaponTypeToString(weaponProficiencies).c_str());
         ImGui::Separator();

        if(!toolProficiencyOptions.empty())
        {
            ImGui::Text("Tool Proficiencies: (Choose 3)");
            if(ImGui::BeginCombo("##Tools1", toolTypeToString(toolTypeSelection1).c_str()))
            {
                for(int i = 0; i < toolProficiencyOptions.size(); i++)
                {
                    if(toolProficiencyOptions[i] == toolTypeSelection2 || toolProficiencyOptions[i] == toolTypeSelection3)
                    {
                        continue;
                    }

                    const bool isSelected = toolProficiencyOptions[i] == toolTypeSelection1;

                    if(ImGui::Selectable(toolTypeToString(toolProficiencyOptions[i]).c_str(), isSelected))
                    {
                        toolTypeSelection1 = toolProficiencyOptions[i];
                        toolProficiencies = toolTypeSelection1 | toolTypeSelection2 | toolTypeSelection3;
                    }

                    if(isSelected)
                    {
                        ImGui::SetItemDefaultFocus();
                    }
                }

                ImGui::EndCombo();
            }
            if(ImGui::BeginCombo("##Tools2", toolTypeToString(toolTypeSelection1).c_str()))
            {
                for(int i = 0; i < toolProficiencyOptions.size(); i++)
                {
                    if(toolProficiencyOptions[i] == toolTypeSelection1 || toolProficiencyOptions[i] == toolTypeSelection3)
                    {
                        continue;
                    }

                    const bool isSelected = toolProficiencyOptions[i] == toolTypeSelection2;

                    if(ImGui::Selectable(toolTypeToString(toolProficiencyOptions[i]).c_str(), isSelected))
                    {
                        toolTypeSelection2 = toolProficiencyOptions[i];
                        toolProficiencies = toolTypeSelection1 | toolTypeSelection2 | toolTypeSelection3;
                    }

                    if(isSelected)
                    {
                        ImGui::SetItemDefaultFocus();
                    }
                }

                ImGui::EndCombo();
            }
            if(ImGui::BeginCombo("##Tools3", toolTypeToString(toolTypeSelection1).c_str()))
            {
                for(int i = 0; i < toolProficiencyOptions.size(); i++)
                {
                    if(toolProficiencyOptions[i] == toolTypeSelection1 || toolProficiencyOptions[i] == toolTypeSelection2)
                    {
                        continue;
                    }

                    const bool isSelected = toolProficiencyOptions[i] == toolTypeSelection3;

                    if(ImGui::Selectable(toolTypeToString(toolProficiencyOptions[i]).c_str(), isSelected))
                    {
                        toolTypeSelection3 = toolProficiencyOptions[i];
                        toolProficiencies = toolTypeSelection1 | toolTypeSelection2 | toolTypeSelection3;
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
        else if (toolProficiencies != ToolType::None)
        {
            ImGui::TextWrapped("Tool Proficinecies: %s", toolTypeToString(toolProficiencies).c_str());

            ImGui::Separator();
        }

         ImGui::TextWrapped("Armour Training: %s", armourTypeToString(armourTraining).c_str());

         std::string equipmentStr1 = "";

        for(Equipment* equipment: equipmentOption1)
        {
            equipmentStr1 += equipment->getName() + ", ";
        }

        if(!additionEquipmentOptions.empty())
        {
            equipmentStr1 += ", " + additionEquipmentOptions;
        }

        equipmentStr1 += moneyOption1.toString();

        ImGui::Separator();
        if(equipmentOption2.empty())
        {
            ImGui::TextWrapped("Starting Equipment: (A) %s; (B) %s", equipmentStr1.c_str(), moneyOption2.toString().c_str());

            if(ImGui::RadioButton("(A)", &equipmentSelection, 0))
            {
                classEquipment = equipmentOption1;
                classMoney = moneyOption1;
            }
            if(ImGui::RadioButton("(B)", &equipmentSelection, 1))
            {
                classEquipment.clear();
                classMoney = moneyOption2;
            }
        }
        else
        {
            std::string equipmentStr2 = "";

            for(Equipment* equipment: equipmentOption2)
            {
                equipmentStr2 += equipment->getName() + ", ";
            }
            equipmentStr2 += moneyOption2.toString();

            ImGui::TextWrapped("Starting Equipment: (A) %s; (B) %s; (C) %s", equipmentStr1.c_str(), equipmentStr2.c_str(), moneyOption3.toString().c_str());

            if(ImGui::RadioButton("(A)", &equipmentSelection, 0))
            {
                classEquipment = equipmentOption1;
                classMoney = moneyOption1;
            }
            if(ImGui::RadioButton("(B)", &equipmentSelection, 1))
            {
                classEquipment = equipmentOption2;
                classMoney = moneyOption2;
            }
            if(ImGui::RadioButton("(C)", &equipmentSelection, 2))
            {
                classEquipment.clear();
                classMoney = moneyOption3;
            }
        }

        if(equipmentSelection == 0 && className == ClassName::Bard)
        {
            ImGui::Text("Tool:");
            if(ImGui::BeginCombo("##ToolOp", toolOptions[toolSelection]->getName().c_str()))
            {
                for(int i = 0; i < toolOptions.size(); i++)
                {
                    const bool isSelected = i == toolSelection;

                    if(ImGui::Selectable(toolOptions[i]->getName().c_str(), isSelected))
                    {
                        toolSelection = i;
                        tool = toolOptions[i];
                    }

                    if(isSelected)
                    {
                        ImGui::SetItemDefaultFocus();
                    }
                }

                ImGui::EndCombo();
            }
        }
        else if(0 == equipmentSelection && ClassName::Cleric == className)
        {
            ImGui::Text("Gear:");
            if(ImGui::BeginCombo("##gear", gearOptions[gearSelection]->getName().c_str()))
            {
                for(int i = 0; i < gearOptions.size(); i++)
                {
                    const bool isSelected = i == gearSelection;

                    if(ImGui::Selectable(gearOptions[i]->getName().c_str(), isSelected))
                    {
                        gearSelection = i;
                        gear = gearOptions[i];
                    }

                    if(isSelected)
                    {
                        ImGui::SetItemDefaultFocus();
                    }
                }

                ImGui::EndCombo();
            }
        }

        if(ImGui::Button("Remove Class"))
        {
            wantsRemoval = true;
        }
         ImGui::PopID();
    }
}

const int& ClassCreator::getLevel() const
{
    return level;
}

const bool& ClassCreator::getWantsRemoval() const
{
    return wantsRemoval;
}

void ClassCreator::cancelRemoval()
{
    wantsRemoval = false;
}
