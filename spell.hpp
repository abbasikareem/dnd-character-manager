#ifndef SPELL_HPP
#define SPELL_HPP

#include <string>
#include <fstream>

#include "enums.hpp"
#include "roll.hpp"

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
    Roll roll;
    DamageType damage_type;
};

std::ostream & operator<<(std::ostream &os, const Spell &spell);

std::istream & operator>>(std::istream &is, Spell spell);

#endif // SPELL_HPP
