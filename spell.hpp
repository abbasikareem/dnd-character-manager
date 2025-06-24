#ifndef SPELL_HPP
#define SPELL_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cassert>

enum TimeUnit {
    ACTION = 0,
    REACTION = 1,
    BONUS_ACTION = 2,
    SECONDS = 3,
    MINUTES = 4,
    HOURS = 5,
    DAYS = 6
};

enum RangeUnit {
    TARGET = 0,
    CONE = 1,
    RADIUS = 2,
    LINE = 3
};

class Spell {
public:

private:
    std::string name;
    std::string description;
    std::string school; // Necromancy, Conjuration, etc.
    int base_level; // 0 = cantrip, 1 = first level, etc.
    std::pair<int, TimeUnit> cast_time; // 1 Action, 10 Minutes, etc.
    bool is_touch;
    bool is_self;
    std::pair<int, RangeUnit> range; // 30 foot cone, 15 foot line, etc.
    bool is_concentration;
    bool has_ritual;
    std::pair<int, TimeUnit> duration; // 1 minute, 1 hour, etc.
    bool is_verbal;
    bool is_semantic;
    bool is_material;
    std::pair<int, int> dice; // first = number, second = die
};

std::ostream & operator<<(std::ostream &os, TimeUnit unit);

std::ostream & operator<<(std::ostream &os, RangeUnit unit);

#endif //SPELL_HPP
