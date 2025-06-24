#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cassert>

#include "enums.hpp"
#include "dice.hpp"

class Item {
public:

private:
    std::string name;
    std::string description;
    std::pair<double, char> cost; // {2, 'g'} = 2 gp
    double weight; // pounds/lbs
    bool is_magic;
};

class Weapon : public Item {
public:

private:
    char weapon_type; // 's' = simple, 'm' = martial
    Dice damage;
    DamageType damage_type;
    std::pair<int, int> range; // ex: 20/60 for handaxe
    bool is_light;
    bool is_heavy;
    bool is_finesse;
    bool is_thrown;
    bool is_two_handed;
    std::pair<bool, Dice> versatile; // first: is versatile, second: new damage
    bool is_ammunition;
    bool is_loading;
    bool is_reach;
};

class Armor : public Item {
public:

private:
    char armor_type; // 'l' = light, 'm' = medium, etc.
    int armor_class;
    std::pair<Ability, int> ac_modifier;
    int min_strength;
    bool stealth_disadvantage;
};

class Mount : public Item {
public:

private:
    Armor *barding; // armor for animals
    int combat_speed; // feet
    int travel_speed; // miles per hour
    int carrying_capacity; // lbs
};

std::ostream & operator<<(std::ostream &os, Item item);

std::istream & operator>>(std::istream &is, Item item);

std::ostream & operator<<(std::ostream &os, Armor armor);

std::istream & operator>>(std::istream &is, Armor armor);

std::ostream & operator<<(std::ostream &os, Weapon weapon);

std::istream & operator>>(std::istream &is, Weapon weapon);

std::ostream & operator<<(std::ostream &os, Mount mount);

std::istream & operator>>(std::istream &is, Mount mount);

#endif // ITEM_HPP
