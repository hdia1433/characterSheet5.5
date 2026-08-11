#pragma once

enum class WeaponProperties:std::uint16_t
{
    None = 0,
    Ammunition = 1 << 0,
    Finesse = 1 << 1,
    Heavy = 1 << 2,
    Light = 1 << 3,
    Loading = 1 << 4,
    Range = 1 << 5,
    Reach = 1 << 6,
    Thrown = 1 << 7,
    TwoHanded = 1 << 8,
    Versatile = 1 << 9
};

inline WeaponProperties operator|(WeaponProperties lhs, WeaponProperties rhs)
{
    return (WeaponProperties)(static_cast<std::underlying_type_t<WeaponProperties>>(lhs) | static_cast<std::underlying_type_t<WeaponProperties>>(rhs));
}
