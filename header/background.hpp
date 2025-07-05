#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include <cassert>

#include "character_class.hpp"
#include "roll.hpp"
#include "effect.hpp"
#include "enums.hpp"
#include "feature.hpp"
#include "item.hpp"
#include "race.hpp"
#include "spell.hpp"

class Background {
public:

private:
    std::set<const Feature*> features;
    std::set<std::string> languages;
    bool armor_proficiencies[4];
    bool weapon_class_proficiencies[4];
    std::set<std::string> weapon_specific_proficiencies;
    std::set<std::string> tool_proficiencies;
    std::set<std::pair<int, const Item*>> starting_equipment;
    bool skills[18];
};

#endif // BACKGROUND_HPP
