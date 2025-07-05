#ifndef SPELL_HPP
#define SPELL_HPP

#include <string>
#include <map>
#include <vector>
#include <sstream>

#include "../utility/csvstream.hpp"
#include "enums.hpp"
#include "roll.hpp"

class Spell {
public:
    Spell(csvstream &is);

    std::ostream & print(std::ostream &os) const;

private:
    std::string name;
    std::string description;
    School school;
    bool is_cantrip;
    int level; // if is_cantrip, this is the cantrip evolution, otherwise level
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

    friend csvstream & operator>>(csvstream &is, Spell & spell);
};

std::ostream & operator<<(std::ostream &os, const Spell & spell);

csvstream & operator>>(csvstream &is, Spell & spell);

#endif // SPELL_HPP
