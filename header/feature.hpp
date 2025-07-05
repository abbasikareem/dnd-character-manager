#ifndef FEATURE_HPP
#define FEATURE_HPP

#include <string>
#include <vector>

#include "effect.hpp"

class Feature {
public:

private:
    std::string name;
    std::string description;
    std::vector<Effect *> effects;
};

#endif // FEATURE_HPP
