#ifndef DICE_HPP
#define DICE_HPP

#include "csvstream.hpp"

struct Roll {
    // The following array stores the number of each size dice (d4--d20)
    // associated with a particular roll. For example, if a certain
    // weapon did 1d8 + 1d4 damage, the corresponding Roll object
    // would store {1, 0, 1, 0, 0, 0}
    int dice[6];
};

bool roll_empty(const Roll & roll);

std::ostream & operator<<(std::ostream &os, const Roll & roll);

std::istream & operator>>(std::istream &is, Roll & roll);

#endif // DICE_HPP
