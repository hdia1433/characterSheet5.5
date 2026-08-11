#pragma once

enum class CoinType
{
    Copper,
    Silver,
    Electrum,
    Gold,
    Platinum
};

struct Money
{
    int amount;
    CoinType coinType;

    inline std::string toString()
    {
        std::string str = std::to_string(amount) + "";

        switch(coinType)
        {
            case CoinType::Copper:
                str += "CP";
                break;
            case CoinType::Silver:
                str += "SP";
                break;
            case CoinType::Electrum:
                str += "EP";
                break;
            case CoinType::Gold:
                str += "GP";
                break;
            case CoinType::Platinum:
                str += "PP";
                break;
        }

        return str;
    }
};
