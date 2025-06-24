#ifndef DICE_HPP
#define DICE_HPP

#include <string>
#include <iostream>
#include <fstream>

struct Roll {
    // Each of the following stores the number of each size dice
    // associated with a particular roll. For example, if a certain
    // weapon did 1d8 + 1d4 damage, the corresponding Roll object
    // would store
    int d4;
    int d6;
    int d8;
    int d10;
    int d12;
    int d20;
};

std::ostream operator<<(std::ostream &os, Roll dice);

std::istream operator>>(std::istream &is, Roll dice);

#endif // DICE_HPP
