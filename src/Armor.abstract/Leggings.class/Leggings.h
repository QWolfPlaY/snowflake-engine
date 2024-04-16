//
// Created by WolfPlay on 4/15/2024.
//

#ifndef RPG_LEGGINGS_H
#define RPG_LEGGINGS_H

#include "Armor.abstract/Armor.h"

class Leggings : public Armor
{
public:
    Leggings(std::string name,
             std::string description,
             float price,
             rarity rarity,
             float baseDefence,
             float baseResistance);

    ~Leggings();

    [[nodiscard]] float calculateMeleeDamageReduction(float damage) const override;

    [[nodiscard]] float calculateMagicDamageReduction(float damage) const override;
};


#endif //RPG_LEGGINGS_H
