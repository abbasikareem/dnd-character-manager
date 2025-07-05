#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <fstream>

#include "enums.hpp"
#include "roll.hpp"

class Item {
public:
    Item();

    Item(csvstream &csv);

private:
    std::string name;
    std::string description;
    std::pair<int, Currency> cost;
    int weight; // pounds/lbs
    bool is_magic;

    friend csvstream & operator>>(csvstream &csv, Item & item);
};

class Weapon : public Item {
public:
    Weapon();

    Weapon(csvstream &csv);

private:
    WeaponType weapon_type;
    Roll damage;
    DamageType damage_type;
    std::pair<int, int> range; // ex: 20/60 for handaxe
    bool is_light;
    bool is_heavy;
    bool is_finesse;
    bool is_thrown;
    bool is_two_handed;
    std::pair<bool, Roll> versatile; // first: is versatile, second: new damage
    bool is_ammunition;
    bool is_loading;
    bool is_reach;

    friend std::ostream & operator<<(std::ostream &os, const Weapon & weapon);
};

class Armor : public Item {
public:
    Armor();

    Armor(csvstream &csv);

private:
    ArmorType armor_type;
    int armor_class;
    std::pair<Ability, int> ac_modifier;
    int min_strength;
    bool stealth_disadvantage;
    
    friend csvstream & operator>>(csvstream &csv, Armor & armor);
};

class Mount : public Item {
public:
    Mount();

    Mount(csvstream &csv);

private:
    Armor *barding; // armor for animals
    int combat_speed; // feet
    int travel_speed; // miles per hour
    int carrying_capacity; // lbs

    friend csvstream & operator>>(csvstream &csv, Mount & mount);
};

std::ostream & operator<<(std::ostream &os, const Item & item);

csvstream & operator>>(csvstream &csv, Item & item);

std::ostream & operator<<(std::ostream &os, const Weapon & weapon);

csvstream & operator>>(csvstream &csv, Weapon & weapon);

std::ostream & operator<<(std::ostream &os, const Armor & armor);

csvstream & operator>>(csvstream &csv, Armor & armor);

std::ostream & operator<<(std::ostream &os, const Mount & mount);

csvstream & operator>>(csvstream &csv, Mount & mount);

#endif // ITEM_HPP
