#pragma once

#include "className.hpp"
#include "abilities.hpp"
#include "skills.hpp"
#include "weaponTypes.hpp"
#include "armourTypes.hpp"

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

public:
    ClassCreator(ClassName className);

    void render(int maxLevel);
};
