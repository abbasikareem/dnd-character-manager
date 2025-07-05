#ifndef ENUMS_HPP
#define ENUMS_HPP

#include <iostream>
#include <string>
#include <exception>

class enum_exception : public std::exception {
public:
    enum_exception(const std::string &msg)
        : msg(msg) {}

    const char * what () const noexcept override {
        return msg.c_str();
    }
private:
    std::string msg;
};

enum Ability {
    STRENGTH = 0,
    DEXTERITY = 1,
    CONSTITUTION = 2,
    INTELLIGENCE = 3,
    WISDOM = 4,
    CHARISMA = 5
};

std::ostream & operator<<(std::ostream &os, Ability ability);

std::istream & operator>>(std::istream &is, Ability & ability);


enum Skill {
    ACROBATICS = 0,
    ANIMAL_HANDLING = 1,
    ARCANA = 2,
    ATHLETICS = 3,
    DECEPTION = 4,
    HISTORY = 5,
    INSIGHT = 6,
    INTIMIDATION = 7,
    INVESTIGATION = 8,
    MEDICINE = 9,
    NATURE = 10,
    PERCEPTION = 11,
    PERFORMANCE = 12,
    PERSUASION = 13,
    RELIGION = 14,
    SLEIGHT_OF_HAND = 15,
    STEALTH = 16,
    SURVIVAL = 17
};

std::ostream & operator<<(std::ostream &os, Skill skill);

std::istream & operator>>(std::istream &is, Skill & skill);

enum TimeUnit {
    INSTANTANEOUS = 0,
    ACTION = 1,
    REACTION = 2,
    BONUS_ACTION = 3,
    SECONDS = 4,
    MINUTES = 5,
    HOURS = 6
};

std::ostream & operator<<(std::ostream &os, TimeUnit time_unit);

std::istream & operator>>(std::istream &is, TimeUnit & time_unit);

enum RangeUnit {
    TARGET = 0,
    CONE = 1,
    SPHERE = 2,
    LINE = 3,
    CUBE = 4,
    CYLLINDER = 5
};

std::ostream & operator<<(std::ostream &os, RangeUnit range_unit);

std::istream & operator>>(std::istream &is, RangeUnit & range_unit);

enum School {
    ABJURATION = 0,
    CONJURATION = 1,
    DIVINATION = 2,
    ENCHANTMENT = 3,
    EVOCATION = 4,
    ILLUSION = 5,
    NECROMANCY = 6,
    TRANSMUTATION = 7
};

std::ostream & operator<<(std::ostream &os, School school);

std::istream & operator>>(std::istream &is, School & school);

enum TargetUnit {
    SELF = 0,
    TOUCH = 1,
    CREATURE = 2,
    OBJECT = 3
};

std::ostream & operator<<(std::ostream &os, TargetUnit target_unit);

std::istream & operator>>(std::istream &is, TargetUnit & target_unit);

enum DamageType {
    ACID = 0,
    BLUEDGEONING = 1,
    COLD = 2,
    FIRE = 3,
    FORCE = 4,
    HEALING = 5,
    LIGHTNING = 6,
    NECROTIC = 7,
    PIERCING = 8,
    POISON = 9,
    PSYCHIC = 10,
    RADIANT = 11,
    SLASHING = 12,
    THUNDER = 13
};

std::ostream & operator<<(std::ostream &os, DamageType damage_type);

std::istream & operator>>(std::istream &is, DamageType & damage_type);

enum Currency {
    COPPER = 0,
    SILVER = 1,
    ELECTRUM = 2,
    GOLD = 3,
    PLATINUM = 4
};

std::ostream & operator<<(std::ostream &os, Currency currency);

std::istream & operator>>(std::istream &is, Currency & currency);

enum WeaponType {
    SIMPLE_MELEE = 0,
    SIMPLE_RANGED = 1,
    MARTIAL_MELEE = 2,
    MARTIAL_RANGED = 3
};

std::ostream & operator<<(std::ostream &os, WeaponType weapon_type);

std::istream & operator>>(std::istream &is, WeaponType & weapon_type);

enum ArmorType {
    LIGHT = 0,
    MEDIUM = 1,
    HEAVY = 2,
    SHIELD = 3
};

std::ostream & operator<<(std::ostream &os, ArmorType armor_type);

std::istream & operator>>(std::istream &is, ArmorType & armor_type);

#endif // ENUMS_HPP
