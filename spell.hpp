#ifndef SPELL_HPP
#define SPELL_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cassert>

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

class Spell {
public:

private:
    std::string name;
    std::string description;
    School school;
    int level; // 0 = cantrip, 1 = first level, etc.
    std::pair<int, TimeUnit> cast_time; // 1 Action, 10 Minutes, etc.
    std::pair<int, TargetUnit> target; // 1 self, 1 touch, 3 creatures, etc.
    std::pair<int, RangeUnit> range; // 30 foot cone, 15 foot line, etc.
    bool is_concentration;
    bool has_ritual;
    std::pair<int, TimeUnit> duration; // 1 minute, 1 hour, etc.
    bool is_verbal;
    bool is_semantic;
    bool is_material;
    std::pair<int, int> dice; // first = number, second = die
};

std::ostream & operator<<(std::ostream &os, const Spell &spell);

std::ostream & operator<<(std::ostream &os, TimeUnit unit);

std::ostream & operator<<(std::ostream &os, RangeUnit unit);

std::ostream & operator<<(std::ostream &os, School school);

std::ostream & operator<<(std::ostream &os, TargetUnit unit);

std::istream & operator>>(std::istream &is, Spell spell);

std::istream & operator>>(std::istream &is, TimeUnit unit);

std::istream & operator>>(std::istream &is, RangeUnit unit);

std::istream & operator>>(std::istream &is, School school);

std::istream & operator>>(std::istream &is, TargetUnit unit);

#endif //SPELL_HPP
