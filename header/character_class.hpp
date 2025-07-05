#ifndef CLASS_HPP
#define CLASS_HPP

#include <string>
#include <set>

#include "enums.hpp"
#include "feature.hpp"
#include "spell.hpp"
#include "roll.hpp"
#include "item.hpp"

class CharacterClass {
public:

private:
    std::string name;
    Roll hit_dice;
    int hit_points;
    bool saving_throws[6];
    bool possible_skills[18];
    bool armor_proficiencies[4];
    bool weapon_class_proficiencies[4];
    std::set<std::string> weapon_specific_proficiencies;
    std::set<std::string> tool_proficiencies;
    std::set<std::pair<int, const Item*>> starting_equipment; // <quantity, Item>
    std::set<Feature *> features_by_level[20];
    std::set<Spell *> spell_list;
    int cantrips_known;
    int spells_known; // -1 if this feature is not used
    int spell_slots[9];
    int level;
};

#endif // CLASS_HPP
