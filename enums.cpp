#include "enums.hpp"

std::ostream & operator<<(std::ostream &os, Ability ability) {
    static std::string labels[6] = {
        "Strength",
        "Dexterity",
        "Constitution",
        "Intelligence",
        "Wisdom",
        "Charisma",
    };

    return os << labels[ability];
}

std::istream & operator>>(std::istream &is, Ability & ability) {
    static std::string labels[6] = {
        "Strength",
        "Dexterity",
        "Constitution",
        "Intelligence",
        "Wisdom",
        "Charisma",
    };

    std::string input;
    is >> input;
    for (int i = 0; i < 6; ++i) {
        if (input == labels[i]) {
            ability = static_cast<Ability>(i);
            return is;
        }
    }

    throw enum_exception("Error: Ability " + input + " does not exist");
}

std::ostream & operator<<(std::ostream &os, Skill skill) {
    static std::string labels[18] = {
        "Acrobatics",
        "Animal Handling",
        "Arcana",
        "Athletics",
        "Deception",
        "History",
        "Insight",
        "Intimidation",
        "Investigation",
        "Medicine",
        "Nature",
        "Perception",
        "Performance",
        "Persuasion",
        "Religion",
        "Sleight of Hand",
        "Stealth",
        "Survival"
    };

    return os << labels[skill];
}

std::istream & operator>>(std::istream &is, Skill & skill) {
    static std::string labels[18] = {
        "Acrobatics",
        "Animal Handling",
        "Arcana",
        "Athletics",
        "Deception",
        "History",
        "Insight",
        "Intimidation",
        "Investigation",
        "Medicine",
        "Nature",
        "Perception",
        "Performance",
        "Persuasion",
        "Religion",
        "Sleight of Hand",
        "Stealth",
        "Survival"
    };

    std::string input;
    is >> input;
    for (int i = 0; i < 18; ++i) {
        if (input == labels[i]) {
            skill = static_cast<Skill>(i);
            return is;
        }
    }

    throw enum_exception("Error: Skill " + input + " does not exist");
}

std::ostream & operator<<(std::ostream &os, TimeUnit time_unit) {
    static std::string labels[7] = {
        "Instantaneous",
        "Action",
        "Reaction",
        "Bonus Action",
        "Seconds",
        "Minutes",
        "Hours"
    };

    return os << labels[time_unit];
}

std::istream & operator>>(std::istream &is, TimeUnit & time_unit) {
    static std::string labels[7] = {
        "Instantaneous",
        "Action",
        "Reaction",
        "Bonus Action",
        "Seconds",
        "Minutes",
        "Hours"
    };

    std::string input;
    is >> input;
    for (int i = 0; i < 7; ++i) {
        if (input == labels[i]) {
            time_unit = static_cast<TimeUnit>(i);
            return is;
        }
    }

    throw enum_exception("Error: TimeUnit " + input + " does not exist");
}

std::ostream & operator<<(std::ostream &os, RangeUnit range_unit) {
    static std::string labels[6] = {
        "Target",
        "Cone",
        "Sphere",
        "Line",
        "Cube",
        "Cyllinder"
    };

    return os << labels[range_unit];
}

std::istream & operator>>(std::istream &is, RangeUnit & range_unit) {
    static std::string labels[6] = {
        "Target",
        "Cone",
        "Sphere",
        "Line",
        "Cube",
        "Cyllinder"
    };

    std::string input;
    is >> input;
    for (int i = 0; i < 6; ++i) {
        if (input == labels[i]) {
            range_unit = static_cast<RangeUnit>(i);
            return is;
        }
    }

    throw enum_exception("Error: RangeUnit " + input + " does not exist");
}

std::ostream & operator<<(std::ostream &os, School school) {
    static std::string labels[8] = {
        "Abjuration",
        "Conjuration",
        "Divination",
        "Enchantment",
        "Evocation",
        "Illusion",
        "Necromancy",
        "Transmutation"
    };

    return os << labels[school];
}

std::istream & operator>>(std::istream &is, School & school) {
    static std::string labels[8] = {
        "Abjuration",
        "Conjuration",
        "Divination",
        "Enchantment",
        "Evocation",
        "Illusion",
        "Necromancy",
        "Transmutation"
    };

    std::string input;
    is >> input;
    for (int i = 0; i < 8; ++i) {
        if (input == labels[i]) {
            school = static_cast<School>(i);
            return is;
        }
    }

    throw enum_exception("Error: School " + input + " does not exist");
}

std::ostream & operator<<(std::ostream &os, TargetUnit target_unit) {
    static std::string labels[4] = {
        "Self",
        "Touch",
        "Creature",
        "Object"
    };

    return os << labels[target_unit];
}

std::istream & operator>>(std::istream &is, TargetUnit & target_unit) {
    static std::string labels[4] = {
        "Self",
        "Touch",
        "Creature",
        "Object"
    };

    std::string input;
    is >> input;
    for (int i = 0; i < 4; ++i) {
        if (input == labels[i]) {
            target_unit = static_cast<TargetUnit>(i);
            return is;
        }
    }

    throw enum_exception("Error: TargetUnit " + input + " does not exist");
}

std::ostream & operator<<(std::ostream &os, DamageType damage_type) {
    static std::string labels[14] = {
        "Acid",
        "Bluedgeoning",
        "Cold",
        "Fire",
        "Force",
        "Healing",
        "Lightning",
        "Necrotic",
        "Piercing",
        "Poison",
        "Psychic",
        "Radiant",
        "Slashing",
        "Thunder"
    };

    return os << labels[damage_type];
}

std::istream & operator>>(std::istream &is, DamageType & damage_type) {
    static std::string labels[14] = {
        "Acid",
        "Bluedgeoning",
        "Cold",
        "Fire",
        "Force",
        "Healing",
        "Lightning",
        "Necrotic",
        "Piercing",
        "Poison",
        "Psychic",
        "Radiant",
        "Slashing",
        "Thunder"
    };

    std::string input;
    is >> input;
    for (int i = 0; i < 14; ++i) {
        if (input == labels[i]) {
            damage_type = static_cast<DamageType>(i);
            return is;
        }
    }

    throw enum_exception("Error: DamageType " + input + " does not exist");
}

std::ostream & operator<<(std::ostream &os, Currency currency) {
    static std::string labels[5] = {
        "Copper",
        "Silver",
        "Electrum",
        "Gold",
        "Platinum"
    };

    return os << labels[currency];
}

std::istream & operator>>(std::istream &is, Currency & currency) {
    static std::string labels[5] = {
        "Copper",
        "Silver",
        "Electrum",
        "Gold",
        "Platinum"
    };

    std::string input;
    is >> input;
    for (int i = 0; i < 5; ++i) {
        if (input == labels[i]) {
            currency = static_cast<Currency>(i);
            return is;
        }
    }

    throw enum_exception("Error: Currency " + input + " does not exist");
}

std::ostream & operator<<(std::ostream &os, WeaponType weapon_type) {
    static std::string labels[4] = {
        "Simple Melee",
        "Simple Ranged",
        "Martial Melee",
        "Martial Ranged"
    };

    return os << labels[weapon_type];
}

std::istream & operator>>(std::istream &is, WeaponType & weapon_type) {
    static std::string labels[4] = {
        "Simple Melee",
        "Simple Ranged",
        "Martial Melee",
        "Martial Ranged"
    };

    std::string input;
    is >> input;
    for (int i = 0; i < 4; ++i) {
        if (input == labels[i]) {
            weapon_type = static_cast<WeaponType>(i);
            return is;
        }
    }

    throw enum_exception("Error: WeaponType " + input + " does not exist");
}

std::ostream & operator<<(std::ostream &os, ArmorType armor_type) {
    static std::string labels[4] = {
        "Light",
        "Medium",
        "Heavy",
        "Shield"
    };

    return os << labels[armor_type];
}

std::istream & operator>>(std::istream &is, ArmorType & armor_type) {
    static std::string labels[4] = {
        "Light",
        "Medium",
        "Heavy",
        "Shield"
    };

    std::string input;
    is >> input;
    for (int i = 0; i < 4; ++i) {
        if (input == labels[i]) {
            armor_type = static_cast<ArmorType>(i);
            return is;
        }
    }
    
    throw enum_exception("Error: ArmorType " + input + " does not exist");
}
