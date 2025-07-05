#include "../header/roll.hpp"

bool Roll::is_empty() const {
    for (int i = 0; i < 6; ++i) {
        if (dice[i] != 0) {
            return false;
        }
    }
    return true;
}

std::ostream & Roll::print(std::ostream &os) const {
    std::string dice_names[6] = {"d4 ", "d6 ", "d8 ", "d10 ", "d12 ", "d20 "};
    
    for (int i = 0; i < 6; ++i) {
        if (dice[i] != 0) {
            os << dice[i] << dice_names[i];
        }
    }

    return os;
}

std::ostream & operator<<(std::ostream &os, const Roll & roll) {
    return roll.print(os);
}

std::istream & operator>>(std::istream &is, Roll & roll) {
    // FORMAT: [#d4] [#d6] [#d8] [#d10] [#d12] [#d20]
    for (int i = 0; i < 6; ++i) {
        is >> roll.dice[i];
    }

    return is;
}
