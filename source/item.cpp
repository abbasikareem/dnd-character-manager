#include "../header/item.hpp"

Item::Item(csvstream &csv) {
    csv >> *this;
}

std::ostream & Item::blurb(std::ostream &os) const {
    os << name;
    if (is_magic) {
        os << " (M)";
    }
}

std::ostream & Item::print(std::ostream &os) const {
    Item::blurb(os);
    if (!description.empty()) {
        os << "\n" << description;
    }
    if (weight != 0) {
        os << "\nWeight: " << weight << " pounds";
    }

    return os;
}

std::ostream & Weapon::blurb(std::ostream &os) const {
    Item::blurb(os);
    os << "\n" << weapon_type << "\n";
    if (range.first != 0 && range.second != 0) {
        os << "(" << range.first << ", " << range.second << ")\n";
    }
    os << damage;
    if (versatile.first) {
        os << "(" << versatile.second << ")";
    }
    os << " " << damage_type;
}

std::ostream & Weapon::print(std::ostream &os) const {
    Weapon::blurb(os);
    os << "\n";

    bool traits[9] = 
        {is_light, is_heavy, is_finesse, is_thrown,
         is_two_handed, versatile.first, is_ammunition,
         is_loading, is_reach};
    static std::string trait_labels[9] =
        {"light", "heavy", "finesse", "thrown", "two-handed",
         "versatile", "ammunition", "loading", "reach"};

    for (int i = 0; i < 9; ++i) {
        if (traits[i]) {
            os << trait_labels[i] << " ";
        }
    }
}

std::ostream & Armor::blurb(std::ostream &os) const {
    Item::blurb(os);
    os << "\n" << armor_type;
}

std::ostream & Armor::print(std::ostream &os) const {
    Armor::blurb(os);
    os << "\nAC: " << armor_class;
    if (ac_modifier.second != -1) {
        os << " + " << ac_modifier.first;
        if (ac_modifier.second != 0) {
            os << " (Max" << ac_modifier.second << ")";
        }
    }
    if (min_strength != 0) {
        os << "\nMinimum Strength: " << min_strength;
    }
    if (stealth_disadvantage) {
        os << "\nStealth Disadvantage";
    }
}

std::ostream & Mount::blurb(std::ostream &os) const {
    Item::blurb(os);
    os << "\nCombat Speed: " << combat_speed << " Feet";
}

std::ostream & Mount::print(std::ostream &os) const {
    Mount::blurb(os);
    os << "\nTravel Speed: " << travel_speed << " Miles per Hour";
    os << "\nCarrying Capacity: " << carrying_capacity << " Pounds";
}

std::ostream & operator<<(std::ostream &os, const Item & item) {
    return item.print(os);
}

csvstream & operator>>(csvstream &csv, Item &item) {
    std::map<std::string, std::string> line;
    csv >> line;

    item.name = line["name"];
    item.description = line["description"];
    item.weight = stoi(line["weight"]);
    item.is_magic = stoi(line["magic"]);

    return csv;
}

csvstream & operator>>(csvstream &csv, Weapon &weapon) {
    std::map<std::string, std::string> line;
    csv >> line;

    weapon.name = line["name"];
    weapon.description = line["description"];
    weapon.weight = stoi(line["weight"]);
    weapon.is_magic = stoi(line["magic"]);
    
    {std::istringstream iss(line["weapon_type"]);
    iss >> weapon.weapon_type;}

    {std::istringstream iss(line["base_damage"]);
    iss >> weapon.damage;}

    {std::istringstream iss(line["damage_type"]);
    iss >> weapon.damage_type;}

    weapon.range.first = stoi(line["weapon_range_close"]);
    weapon.range.second = stoi(line["weapon_range_far"]);

    weapon.is_light = stoi(line["light"]);
    weapon.is_heavy = stoi(line["heavy"]);
    weapon.is_finesse = stoi(line["finesse"]);
    weapon.is_thrown = stoi(line["thrown"]);
    weapon.is_two_handed = stoi(line["two_handed"]);
    weapon.versatile.first = stoi(line["versatile"]);
    {std::istringstream iss(line["versatile_damage"]);
    iss >> weapon.versatile.second;}
    weapon.is_ammunition = stoi(line["ammunition"]);
    weapon.is_loading = stoi(line["loading"]);
    weapon.is_reach = stoi(line["reach"]);
}
