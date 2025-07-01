#ifndef SPELL_HPP
#define SPELL_HPP

#include <string>
#include <fstream>

#include "enums.hpp"
#include "roll.hpp"

class Spell {
public:
    Spell();

    // void set_name(const std::string &name_in);

    // void set_description(const std::string &description_in);

    // void set_school(School school_in);

    // void set_level(int level_in);

    // void set_cast_time(int ntime, TimeUnit utime);

    // void set_target(int ntarget, TargetUnit utarget);

    // void set_range(int nrange, RangeUnit urange);

    // void set_concentration(bool is_con_in);

    // void set_ritual(bool is_rit_in);

    // void set_duration(int nduration, TimeUnit uduration);

    // void set_verbal(bool is_verbal_in);

    // void set_semantic(bool is_semantic_in);

    // void set_material(bool is_material_in);

    // void set_roll(Roll roll_in);

    // void set_damage_type(DamageType damage_type_in);

    // std::ostream & cast(std::ostream &os) const;

    // std::ostream & ritual_cast(std::ostream &os) const;

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

    friend std::istream & operator<<(std::istream &is, Spell spell);
};

std::ostream & operator<<(std::ostream &os, const Spell &spell);

std::istream & operator>>(std::istream &is, Spell spell);

#endif // SPELL_HPP
