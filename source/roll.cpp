#include "../header/roll.hpp"

Roll::Roll(std::istream &is) {
    is >> *this;
}

Roll::Roll(const std::string & in) {
    std::istringstream iss(in);
    iss >> *this;
}

bool Roll::is_empty() const {
    for (int i = 0; i < 6; ++i) {
        if (dice[i] != 0) {
            return false;
        }
    }
    return true;
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
