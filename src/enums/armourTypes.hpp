#pragma once

enum class ArmourType:std::uint8_t
{
    None = 0,
    Light = 1 << 0,
    Medium = 1 << 1,
    Heavy = 1 << 2,
    Shields = 1 << 3
};

inline ArmourType operator|(ArmourType lhs, ArmourType rhs)
{
    return(ArmourType)(static_cast<std::underlying_type_t<ArmourType>>(lhs) | static_cast<std::underlying_type_t<ArmourType>>(rhs));
}

inline ArmourType operator&(ArmourType lhs, ArmourType rhs)
{
    return (ArmourType)(static_cast<std::underlying_type_t<ArmourType>>(lhs) & static_cast<std::underlying_type_t<ArmourType>>(rhs));
}

inline bool hasArmourType(ArmourType armourType, ArmourType checkingFor)
{
    return (armourType & checkingFor) != ArmourType::None;
}

inline std::string armourTypeToString(const ArmourType& armourType)
{
    if(armourType == ArmourType::None)
    {
        return "None";
    }

    std::string str = "";

    if(hasArmourType(armourType, ArmourType::Light))
    {
        str += "Light, ";
    }
    if(hasArmourType(armourType, ArmourType::Medium))
    {
        str += "Medium, ";
    }
    if(hasArmourType(armourType, ArmourType::Heavy))
    {
        str += "Heavy, ";
    }
    if(hasArmourType(armourType, ArmourType::Shields))
    {
        str += "Shields, ";
    }

    str = str.substr(0, str.size() - 2);

    return str;
}
