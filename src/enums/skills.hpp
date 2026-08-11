#pragma once

enum class Skill:std::uint32_t
{
    None = 0,
    Acrobatics = 1 << 0,
    AnimalHandling = 1 << 1,
    Arcana = 1 << 2,
    Athletics = 1 << 3,
    Deception = 1 << 4,
    History = 1 << 5,
    Insight = 1 << 6,
    Intimidation = 1 << 7,
    Investigation = 1 << 8,
    Medicine = 1 << 9,
    Nature = 1 << 10,
    Perception = 1 << 11,
    Performance = 1 << 12,
    Persuasion = 1 << 13,
    Religion = 1 << 14,
    SleightOfHand = 1 << 15,
    Stealth = 1 << 16,
    Survival = 1 << 17
};

inline Skill operator|(Skill lhs, Skill rhs)
{
    return (Skill)(static_cast<std::underlying_type_t<Skill>>(lhs) | static_cast<std::underlying_type_t<Skill>>(rhs));
}


inline Skill operator&(Skill lhs, Skill rhs)
{
    return (Skill)(static_cast<std::underlying_type_t<Skill>>(lhs) & static_cast<std::underlying_type_t<Skill>>(rhs));
}

inline bool hasSkill(Skill skill, Skill toCheck)
{
    return (skill & toCheck) != Skill::None;
}

inline std::string skillToString(Skill skill)
{
    if(skill == Skill::None)
    {
        return "None";
    }

    std::string str = "";

    if(hasSkill(skill, Skill::Acrobatics))
    {
        str += "Acrobatics, ";
    }
    if(hasSkill(skill, Skill::AnimalHandling))
    {
        str += "AnimalHandling, ";
    }
    if(hasSkill(skill, Skill::Arcana))
    {
        str += "Arcana, ";
    }
    if(hasSkill(skill, Skill::Athletics))
    {
        str += "Athletics, ";
    }
    if(hasSkill(skill, Skill::Deception))
    {
        str += "Deception, ";
    }
    if(hasSkill(skill, Skill::History))
    {
        str += "History, ";
    }
    if(hasSkill(skill, Skill::Insight))
    {
        str += "Insight, ";
    }
    if(hasSkill(skill, Skill::Intimidation))
    {
        str += "Intimidation, ";
    }
    if(hasSkill(skill, Skill::Investigation))
    {
        str += "Investigation, ";
    }
    if(hasSkill(skill, Skill::Medicine))
    {
        str += "Medicine, ";
    }
    if(hasSkill(skill, Skill::Nature))
    {
        str += "Nature, ";
    }
    if(hasSkill(skill, Skill::Perception))
    {
        str += "Perception, ";
    }
    if(hasSkill(skill, Skill::Performance))
    {
        str += "Performance, ";
    }
    if(hasSkill(skill, Skill::Persuasion))
    {
        str += "Persuasion, ";
    }
    if(hasSkill(skill, Skill::Religion))
    {
        str += "Religion, ";
    }
    if(hasSkill(skill, Skill::SleightOfHand))
    {
        str += "SleightOfHand, ";
    }
    if(hasSkill(skill, Skill::Stealth))
    {
        str += "Stealth, ";
    }
    if(hasSkill(skill, Skill::Survival))
    {
        str += "Survival, ";
    }

    str = str.substr(0, str.size() - 2);

    return str;
}
