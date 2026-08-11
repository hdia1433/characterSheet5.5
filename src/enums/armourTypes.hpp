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
