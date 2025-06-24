#ifndef DICE_HPP
#define DICE_HPP

#include <string>
#include <iostream>
#include <fstream>

struct Dice {
    int d4;
    int d6;
    int d8;
    int d10;
    int d12;
    int d20;
};

std::ostream operator<<(std::ostream &os, Dice dice);

std::istream operator>>(std::istream &is, Dice dice);

#endif // DICE_HPP
