//
// Created by WolfPlay on 4/10/2024.
//

#include "Weapon.h"

#include <utility>

Weapon::Weapon(
        std::string name,
        std::string description,
        float price,
        type type,
        rarity rarity,
        float damage,
        float armorPenetration,
        float attackSpeed,
        float critChance,
        float critDamageMult
) : Item(
        std::move(name),
        std::move(description),
        price,
        type,
        rarity
),
    _baseDamage(damage),
    _armorPenetration(armorPenetration),
    _attackSpeed(attackSpeed),
    _critChance(critChance),
    _critDamageMultiplier(critDamageMult)
{}

bool Weapon::isHitCritical()
{
    std::uniform_int_distribution<> rand(100, 10000);

    if (rand(Weapon::_gen) / 100.0 < Weapon::_critChance) {
        return true;
    } else {
        return false;
    }
}

float Weapon::getDamage() const {
    return _baseDamage;
}

float Weapon::getArmorPenetration() const {
    return _armorPenetration;
}

float Weapon::getAttackSpeed() const {
    return _attackSpeed;
}

void Weapon::attack(Enemy *target)
{
    float resultingDamage = Weapon::_baseDamage;
    if (Weapon::isHitCritical()) { resultingDamage *= Weapon::_critDamageMultiplier; }

    target->takeDamage(resultingDamage, Weapon::_armorPenetration);
}