#include "spell.hpp"

Spell::Spell(csvstream &is) {
    is >> *this;
}

std::ostream & Spell::print(std::ostream &os) {
    os << name << "\n";
    os << "Level " << level << " " << school << "\n";
    
    if (is_concentration) {
        os << "(C) ";
    }
    if (has_ritual) {
        os << "(R) ";
    }
    if (is_verbal) {
        os << "(V) ";
    }
    if (is_semantic) {
        os << "(S) ";
    }
    if (is_material) {
        os << "(M) ";
    }
    os << "\n";

    os << description;
    os << "Cast time: " << cast_time.first << " " << cast_time.second << "\n";
    
    if (target.second == SELF || target.second == TOUCH) {
        os << "Target: " << target.second;
    }
    else {
        if (target.first == 1) {
            os << "Target: " << target.first << " " << target.second << "\n";
        }
        else {
            os << "Target: " << target.first << " " << target.second << "s\n";
        }
        os << "Range: " << range.first << " " << range.second << "\n";
    }
    
    if (duration.first == 1) {
        os << "Duration: " << duration.first << " " << duration.second << "\n";
    }
    else {
        os << "Duration: " << duration.first << " " << duration.second << "s\n";
    }

    if (!roll_empty(roll)) {
        os << "Roll: " << roll << " " << damage_type << "\n";
    }
}

std::ostream & operator<<(std::ostream &os, Spell &spell) {
    return spell.print(os); 
}

csvstream & operator>>(csvstream &is, Spell &spell) {
    std::map<std::string, std::string> line;
    is >> line;

    spell.name = line["name"];
    spell.description = line["description"];
    spell.school = static_cast<School>(stoi(line["school"]));

    spell.cast_time.first = stoi(line["cast_time_number"]);
    // spell.cast_time.second = static_cast<TimeUnit>(stoi(line["cast_time_unit"]));

    spell.target.first = stoi(line["target_number"]);
    // spell.target.second = static_cast<TargetUnit>(stoi(line["target_unit"]));

    spell.range.first = stoi(line["range_number"]);
    // spell.range.second = static_cast<RangeUnit>(stoi(line["range_unit"]));

    spell.is_concentration = stoi(line["concentration"]);
    spell.has_ritual = stoi(line["ritual"]);

    spell.duration.first = stoi(line["duration_number"]);
    // spell.duration.second = static_cast<TimeUnit>(stoi(line["duration_unit"]));

    spell.is_verbal = stoi(line["verbal"]);
    spell.is_semantic = stoi(line["semantic"]);
    spell.is_material = stoi(line["material"]);

    std::istringstream iss(line["roll"]);
    iss >> spell.roll;

    // spell.damage_type = static_cast<DamageType>(stoi(line["damage_type"]));

    return is;
}
