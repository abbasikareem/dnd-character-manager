#include "roll.hpp"
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    Roll r;
    stringstream ss("1 2 0 0 3 4");
    ss >> r;
    cout << r;
}
