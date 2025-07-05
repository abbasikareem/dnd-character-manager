#include "../header/spell.hpp"

Spell::Spell(csvstream &is) {
    is >> *this;
}

std::ostream & Spell::print(std::ostream &os) const {
    os << name << "\n";
    if (is_cantrip) {
        os << school << " Cantrip\n";
    }
    else {
        os << "Level " << level << " " << school << "\n";
    }

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

        if (range.second == TARGET) {
            os << "Range: " << range.first << " Feet\n";
        }
        else{
            os << "Range: " << range.first << " Foot " << range.second << "\n";
        }
    }
    
    if (duration.second == INSTANTANEOUS) {
        os << "Duration: " << duration.second << "\n";
    }
    else if (duration.first == 1) {
        os << "Duration: " << duration.first << " " << duration.second << "\n";
    }
    else {
        os << "Duration: " << duration.first << " " << duration.second << "s\n";
    }

    if (!roll.is_empty()) {
        os << "Roll: " << roll << damage_type << "\n";
    }

    return os;
}

std::ostream & operator<<(std::ostream &os, const Spell & spell) {
    return spell.print(os); 
}

csvstream & operator>>(csvstream &is, Spell & spell) {
    std::map<std::string, std::string> line;
    is >> line;

    spell.name = line["name"];
    spell.description = line["description"];
    
    std::istringstream is_school(line["school"]);
    is_school >> spell.school;

    spell.is_cantrip = stoi(line["cantrip"]);
    spell.level = stoi(line["level"]);

    spell.cast_time.first = stoi(line["cast_time_number"]);
    std::istringstream is_spell(line["cast_time_unit"]);
    is_spell >> spell.cast_time.second;

    spell.target.first = stoi(line["target_number"]);
    std::istringstream is_target(line["target_unit"]);
    is_target >> spell.target.second;

    spell.range.first = stoi(line["range_number"]);
    std::istringstream is_range(line["range_unit"]);
    is_range >> spell.range.second;

    spell.is_concentration = stoi(line["concentration"]);
    spell.has_ritual = stoi(line["ritual"]);

    spell.duration.first = stoi(line["duration_number"]);
    std::istringstream is_duration(line["duration_unit"]);
    is_duration >> spell.duration.second;

    spell.is_verbal = stoi(line["verbal"]);
    spell.is_semantic = stoi(line["semantic"]);
    spell.is_material = stoi(line["material"]);

    std::istringstream is_roll(line["roll"]);
    is_roll >> spell.roll;

    std::istringstream is_damage_type(line["damage_type"]);
    is_damage_type >> spell.damage_type;

    return is;
}
