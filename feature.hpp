#ifndef FEATURE_HPP
#define FEATURE_HPP

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
#include "item.hpp"
#include "race.hpp"
#include "spell.hpp"

class Feature {
public:

private:
    std::string name;
    std::string description;
    std::vector<Effect *> effects;
};

#endif // FEATURE_HPP
