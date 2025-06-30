#ifndef RACE_HPP
#define RACE_HPP

#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include <cassert>

#include "feature.hpp"

class Race {
public:

private:
    std::string name;
    int ability_score_increases[6];
    bool skill_proficiencies[18];
    char size;
    int speed;
    std::set<const Feature*> features;
    std::set<std::string> languages;
    bool armor_proficiencies[4];
    bool weapon_class_proficiencies[4];
    std::set<std::string> weapon_specific_proficiencies;
    std::set<std::string> tool_proficiencies;
};

std::ostream & operator<<(std::ostream &os, Race race);

std::istream & operator>>(std::istream &is, Race race);

#endif // RACE_HPP
