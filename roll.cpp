#include "roll.hpp"

std::ostream & operator<<(std::ostream &os, Roll roll) {
    if (roll.dice[0] != 0) {
        os << roll.dice[0] << "d4 ";
    }
    if (roll.dice[1] != 0) {
        os << roll.dice[1] << "d6 ";
    }
    if (roll.dice[2] != 0) {
        os << roll.dice[2] << "d8 ";
    }
    if (roll.dice[3] != 0) {
        os << roll.dice[3] << "d10 ";
    }
    if (roll.dice[4] != 0) {
        os << roll.dice[4] << "d12 ";
    }
    if (roll.dice[5] != 0) {
        os << roll.dice[5] << "d20 ";
    }
    return os;
}

std::ostream & operator<<(std::ostream &os, const Roll & roll) {
    std::string dice_names[6] = {"d4 ", "d6 ", "d8 ", "d10 ", "d12 ", "d20 "};
    
    for (int i = 0; i < 6; ++i) {
        if (roll.dice[i] != 0) {
            os << roll.dice[i] << dice_names[i];
        }
    }

    return os;
}

std::istream & operator>>(std::istream &is, Roll & roll) {
    // FORMAT: [#d4] [#d6] [#d8] [#d10] [#d12] [#d20]
    for (int i = 0; i < 6; ++i) {
        is >> roll.dice[i];
    }

    return is;
}
