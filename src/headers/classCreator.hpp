#pragma once

#include "className.hpp"
#include "abilities.hpp"
#include "skills.hpp"
#include "weaponTypes.hpp"
#include "armourTypes.hpp"
#include "equipment.hpp"
#include "toolType.hpp"
#include "tool.hpp"
#include "adventuringGear.hpp"

class ClassCreator
{
private:
    int level;
    ClassName className;
    bool wantsRemoval;

    Ability primaryAbilities;
    int hitDie;
    Ability savingThrowProficiencies;
    std::vector<Skill> skillOptions;
    Skill skillSelection1;
    Skill skillSelection2;
    Skill skillSelection3;
    Skill skillProficiencies;
    WeaponType weaponProficiencies;
    std::vector<ToolType> toolProficiencyOptions;
    ToolType toolTypeSelection1;
    ToolType toolTypeSelection2;
    ToolType toolTypeSelection3;
    ToolType toolProficiencies;
    ArmourType armourTraining;

    int equipmentSelection;
    std::vector<Equipment*> equipmentOption;
    std::string additionEquipmentOptions;
    std::vector<Tool*> toolOptions;
    int toolSelection;
    Tool* tool;
    std::vector<AdventuringGear*> gearOptions;
    int gearSelection;
    AdventuringGear* gear;
    std::vector<Equipment*> classEquipment;

    Money moneyOption1;
    Money moneyOption2;
    Money classMoney;

public:
    ClassCreator(const ClassName& className);
    ~ClassCreator();

    void render(int maxLevel);

    const int& getLevel() const;
    const bool& getWantsRemoval() const;

    void cancelRemoval();
};
