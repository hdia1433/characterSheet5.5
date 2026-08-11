#pragma once

#include "className.hpp"
#include "abilities.hpp"
#include "skills.hpp"
#include "weaponTypes.hpp"
#include "armourTypes.hpp"
#include "equipment.hpp"

class ClassCreator
{
private:
    int level;
    ClassName className;

    Ability primaryAbilities;
    int hitDie;
    Ability savingThrowProficiencies;
    std::vector<Skill> skillOptions;
    Skill skillSelection1;
    Skill skillSelection2;
    Skill skillProficiencies;
    WeaponType weaponProficiencies;
    ArmourType armourTraining;

    int equipmentSelection;
    std::vector<Equipment*> equipmentOption;
    std::vector<Equipment*> classEquipment;

    Money moneyOption1;
    Money moneyOption2;
    Money classMoney;

public:
    ClassCreator(const ClassName& className);
    ~ClassCreator();

    void render(int maxLevel);

    int& getLevel();
};
