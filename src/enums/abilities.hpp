#pragma once

enum class Ability:std::uint8_t
{
    None = 0,
    Strength = 1 << 0,
    Dexterity = 1 << 1,
    Constitution = 1 << 2,
    Intelligence = 1 << 3,
    Wisdom = 1 << 4,
    Charisma = 1 << 5
};

inline Ability operator|(Ability lhs, Ability rhs)
{
    return (Ability)(static_cast<std::underlying_type_t<Ability>>(lhs) | static_cast<std::underlying_type_t<Ability>>(rhs));
}


inline Ability operator&(Ability lhs, Ability rhs)
{
    return (Ability)(static_cast<std::underlying_type_t<Ability>>(lhs) & static_cast<std::underlying_type_t<Ability>>(rhs));
}

inline bool hasAbility(Ability ability, Ability toCheck)
{
    return (ability & toCheck) != Ability::None;
}

inline std::string abilityToString(Ability ability)
{
    if(ability == Ability::None)
    {
        return "None";
    }

    std::string abilityName = "";

    if(hasAbility(ability, Ability::Strength))
    {
        abilityName += "Strength, ";
    }
    if(hasAbility(ability, Ability::Dexterity))
    {
        abilityName += "Dexterity, ";
    }
    if(hasAbility(ability, Ability::Constitution))
    {
        abilityName += "Constitution, ";
    }
    if(hasAbility(ability, Ability::Intelligence))
    {
        abilityName += "Intelligence, ";
    }
    if(hasAbility(ability, Ability::Wisdom))
    {
        abilityName += "Wisdom, ";
    }
    if(hasAbility(ability, Ability::Charisma))
    {
        abilityName += "Charisma, ";
    }

    abilityName = abilityName.substr(0, abilityName.size() - 2);
}
