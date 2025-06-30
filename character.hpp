#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cassert>
#include <set>

#include "background.hpp"
#include "character_class.hpp"
#include "roll.hpp"
#include "effect.hpp"
#include "enums.hpp"
#include "feature.hpp"
#include "item.hpp"
#include "race.hpp"
#include "spell.hpp"

class Character {
public:
    class Inventory {
    public:

    private:
        std::vector<const Weapon*> weapons;
        std::vector<const Armor*> armor;
        Currency money[5];
        std::set<std::pair<int, const Item*>> equipment; // <quantity, Item>
        std::set<std::pair<int, const Item*>> treasure; // <quantity, Item>
    };

    class Spellbook {
    public:

    private:
        int spell_ability_modifier;
        int spell_save_dc;
        int spell_attack_bunus;
        int num_prepared_spells;
        std::set<const Spell*> prepared_spells;
        // The following are arrays where the index corresponds to the spell
        // level, with 0 = cantrip, 1 = level 1,..., 9 = level 9.
        std::pair<int, int> spell_slots[10];
        std::set<const Spell*> spells[10];
    };

    class CombatInfo {
    public:

    private:
        int armor_class;
        int initiative;
        int speed;
        char size;
        std::pair<int, int> hit_points; // <current, max>
        std::tuple<Roll, int, int> hit_dice; // <Roll, current, max>
        std::pair<int, int> death_saving_throws; // <success, failure>
        std::vector<const Effect*> effects;
        bool damange_resistances[14];
        bool armor_proficiencies[4];
        bool weapon_class_proficiencies[4];
        std::set<std::string> weapon_specific_proficiencies;
        std::set<std::string> tool_proficiencies;
    };

    class Stats {
    public:

    private:
        bool abilities[6]; // Ordered as in enum.hpp
        bool skills[18]; // Ordered as in enum.hpp
        bool saving_throws[6]; // Ordered as in enum.hpp
        int proficiency_bonus;
        bool inspiration;
        int passive_wisdom;
    };

    class Biography {
    public:

    private:
        int age;
        int height; // inches
        int weight; // pounds
        std::string eyes;
        std::string skin;
        std::string hair;
        std::vector<std::string> allies;
        std::vector<std::string> ideals;
        std::vector<std::string> bonds;
        std::vector<std::string> flaws;
        std::vector<std::string> personality_traits;
        std::string backstory;
        std::string alignment;
        std::set<std::string> languages;
    };

private:
    std::string name;
    Race *race;
    CharacterClass *character_class;
    Background *background;
    int level;
    bool using_experience;
    int experience;
    std::set<const Feature*> active_features;
    Biography biography;
    Stats stats;
    CombatInfo combatinfo;
    Spellbook spellbook;
    Inventory inventory;
};

#endif // CHARACTER_HPP
