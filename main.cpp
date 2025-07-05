#include <iostream>
#include <sstream>

#include "spell.hpp"

int main() {
    csvstream csv("random_test.csv");
    Spell s(csv);
    std::cout << s;
}
