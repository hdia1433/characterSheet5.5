#pragma once

enum class ToolType:uint16_t
{
    None = 0,
    Bagpipes = 1 << 0,
    Drum = 1 << 1,
    Dulcimer = 1 << 2,
    Flute = 1 << 3,
    Horn = 1 << 4,
    Lute = 1 << 5,
    Lyre = 1 << 6,
    PanFlute = 1 << 7,
    Shawm = 1 << 8,
    Viol = 1 << 9
};

inline ToolType operator|(ToolType lhs, ToolType rhs)
{
    return (ToolType)(static_cast<std::underlying_type_t<ToolType>>(lhs) | static_cast<std::underlying_type_t<ToolType>>(rhs));
}

inline ToolType operator&(ToolType lhs, ToolType rhs)
{
    return (ToolType)(static_cast<std::underlying_type_t<ToolType>>(lhs) & static_cast<std::underlying_type_t<ToolType>>(rhs));
}

inline bool hasToolType(const ToolType& toolType, const ToolType& checkingFor)
{
    return (toolType & checkingFor) != ToolType::None;
}

inline std::string toolTypeToString(const ToolType& toolType)
{
    if(toolType == ToolType::None)
    {
        return "None";
    }

    std::string str = "";

    if(hasToolType(toolType, ToolType::Bagpipes))
    {
        str += "Bagpipes, ";
    }
    if(hasToolType(toolType, ToolType::Drum))
    {
        str += "Drum, ";
    }
    if(hasToolType(toolType, ToolType::Dulcimer))
    {
        str += "Dulcimer, ";
    }
    if(hasToolType(toolType, ToolType::Flute))
    {
        str += "Flute, ";
    }
    if(hasToolType(toolType, ToolType::Horn))
    {
        str += "Horn, ";
    }
    if(hasToolType(toolType, ToolType::Lute))
    {
        str += "Lute, ";
    }
    if(hasToolType(toolType, ToolType::Lyre))
    {
        str += "Lyre, ";
    }
    if(hasToolType(toolType, ToolType::PanFlute))
    {
        str += "PanFlute, ";
    }
    if(hasToolType(toolType, ToolType::Shawm))
    {
        str += "Shawm, ";
    }
    if(hasToolType(toolType, ToolType::Viol))
    {
        str += "Viol, ";
    }

    str = str.substr(0, str.size() - 2);

    return str;
}
