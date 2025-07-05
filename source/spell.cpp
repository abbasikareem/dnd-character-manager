#include "../header/spell.hpp"

Spell::Spell(csvstream &is) {
    is >> *this;
}

std::ostream & operator<<(std::ostream &os, const Spell & spell) {
    os << spell.name << "\n";
    if (spell.is_cantrip) {
        os << spell.school << " Cantrip\n";
    }
    else {
        os << "Level " << spell.level << " " << spell.school << "\n";
    }

    if (spell.is_concentration) {
        os << "(C) ";
    }
    if (spell.has_ritual) {
        os << "(R) ";
    }
    if (spell.is_verbal) {
        os << "(V) ";
    }
    if (spell.is_semantic) {
        os << "(S) ";
    }
    if (spell.is_material) {
        os << "(M) ";
    }
    os << "\n";

    os << spell.description;
    os << "Cast time: " << spell.cast_time.first << " " << spell.cast_time.second << "\n";
    
    if (spell.target.second == SELF || spell.target.second == TOUCH) {
        os << "Target: " << spell.target.second;
    }
    else {
        if (spell.target.first == 1) {
            os << "Target: " << spell.target.first << " " << spell.target.second << "\n";
        }
        else {
            os << "Target: " << spell.target.first << " " << spell.target.second << "s\n";
        }

        if (spell.range.second == TARGET) {
            os << "Range: " << spell.range.first << " Feet\n";
        }
        else{
            os << "Range: " << spell.range.first << " Foot " << spell.range.second << "\n";
        }
    }
    
    if (spell.duration.second == INSTANTANEOUS) {
        os << "Duration: " << spell.duration.second << "\n";
    }
    else if (spell.duration.first == 1) {
        os << "Duration: " << spell.duration.first << " " << spell.duration.second << "\n";
    }
    else {
        os << "Duration: " << spell.duration.first << " " << spell.duration.second << "s\n";
    }

    if (!spell.roll.is_empty()) {
        os << "Roll: " << spell.roll << spell.damage_type << "\n";
    }

    return os; 
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
