#ifndef ENUMS_HPP
#define ENUMS_HPP

// TODO: ADD INSERTION OVERLOADS FOR EACH TYPE :)

enum Ability {
    STRENGTH = 0,
    DEXTERITY = 1,
    CONSTITUTION = 2,
    INTELLIGENCE = 3,
    WISDOM = 4,
    CHARISMA = 5
};

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

enum TimeUnit {
    INSTANTANEOUS = 0,
    ACTION = 1,
    REACTION = 2,
    BONUS_ACTION = 3,
    SECONDS = 4,
    MINUTES = 5,
    HOURS = 6
};

enum RangeUnit {
    TARGET = 0,
    CONE = 1,
    SPHERE = 2,
    LINE = 3,
    CUBE = 4,
    CYLLINDER = 5
};

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

enum TargetUnit {
    SELF = 0,
    TOUCH = 1,
    CREATURE = 2,
    OBJECT = 3
};

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

#endif // ENUMS_HPP
