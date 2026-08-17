#pragma once

#include <unordered_map>
#include "className.hpp"

#include "scene.hpp"
#include "skills.hpp"
#include "background.hpp"
#include "classCreator.hpp"

class CreateChar: public Scene
{
private:
    std::unordered_map<ClassName, ClassCreator> chosenClasses;

    bool classPopup;
    ClassName classToRemove;
    bool removePopup;
    const char* classOptions[13];
    int currentClass;

    int skill1;
    int skill2;

    Skill barbarianSkills[6];

    int classEquipmentSeleciton;

    Background background;
    const char* backgroundOptions[1];
    int backgroundSkillType;

public:
    CreateChar();

    void render() override;

private:
    void classSection();

    void originSelection();
};
