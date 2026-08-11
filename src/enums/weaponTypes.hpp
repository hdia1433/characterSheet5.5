#pragma once

enum class WeaponType:std::uint8_t
{
    None = 0,
    Simple = 1 << 0,
    Martial = 1 << 1
};

inline WeaponType operator|(WeaponType lhs, WeaponType rhs)
{
    return (WeaponType)(static_cast<std::underlying_type_t<WeaponType>>(lhs) | static_cast<std::underlying_type_t<WeaponType>>(rhs));
}

inline WeaponType operator&(WeaponType lhs, WeaponType rhs)
{
    return (WeaponType)(static_cast<std::underlying_type_t<WeaponType>>(lhs) & static_cast<std::underlying_type_t<WeaponType>>(rhs));
}

inline bool hasWeaponType(WeaponType weaponType, WeaponType toCheck)
{
    return (weaponType & toCheck) != WeaponType::None;
}

inline std::string weaponTypeToString(WeaponType weaponType)
{
    if(weaponType == WeaponType::None)
    {
        return "None";
    }

    std::string str = "";

    if(hasWeaponType(weaponType, WeaponType::Simple))
    {
        str += "Simple, ";
    }
    if(hasWeaponType(weaponType, WeaponType::Martial))
    {
        str += "Martial, ";
    }

    str = str.substr(0, str.size() - 2);

    return str;
}
